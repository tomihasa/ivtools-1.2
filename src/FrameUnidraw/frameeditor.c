/*
 * Copyright (c) 1994-1996 Vectaport Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and
 * its documentation for any purpose is hereby granted without fee, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the names of the copyright holders not be used in
 * advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission.  The copyright holders make
 * no representations about the suitability of this software for any purpose.
 * It is provided "as is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL,
 * INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
 * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 */

#include <FrameUnidraw/framecomps.h>
#include <FrameUnidraw/frameeditor.h>
#include <FrameUnidraw/framestates.h>
#include <FrameUnidraw/frameviews.h>

#include <OverlayUnidraw/ovcomps.h>
#include <OverlayUnidraw/ovkit.h>
#include <OverlayUnidraw/ovviewer.h>

#include <IVGlyph/textedit.h>

#include <UniIdraw/idarrows.h>
#include <UniIdraw/idvars.h>

#include <Unidraw/Components/text.h>
#include <Unidraw/Graphic/ellipses.h>
#include <Unidraw/Tools/grcomptool.h>

#include <Unidraw/catalog.h>
#include <Unidraw/ctrlinfo.h>
#include <Unidraw/keymap.h>
#include <Unidraw/unidraw.h>

#include <InterViews/box.h>
#include <InterViews/border.h>
#include <InterViews/glue.h>

#include <IV-2_6/InterViews/frame.h>
#include <IV-2_6/InterViews/panner.h>
#include <IV-2_6/InterViews/tray.h>

#include <ComTerp/comterpserv.h>

#include <stdio.h>

implementActionCallback(FrameEditor)

/*****************************************************************************/

FrameEditor::FrameEditor(OverlayComp* gc, OverlayKit* ok)
: ComEditor(false, ok)
{
    Init(gc);
}

FrameEditor::FrameEditor(const char* file, OverlayKit* ok)
: ComEditor(false, ok)
{
    if (file == nil) {
	Init();

    } else {
	Catalog* catalog = unidraw->GetCatalog();
	OverlayComp* comp;

	if (catalog->Retrieve(file, (Component*&) comp)) {
	    Init(comp);

	} else {
	    Init();
	    fprintf(stderr, "flipbook: couldn't open %s\n", file);
	}
    }
}

FrameEditor::FrameEditor(boolean initflag, OverlayKit* ok) 
: ComEditor(initflag, ok) {}

FrameEditor::~FrameEditor() {}

void FrameEditor::Init (OverlayComp* comp, const char* name) {
  _curr_other = _prev_other = 0;
  _texteditor = nil;
  if (!comp) comp = new FrameIdrawComp;
  _terp = new ComTerpServ();
  add_comterp("Flipbook", _terp);
  _overlay_kit->Init(comp, name);
  InitFrame();
}

void FrameEditor::InitFrame() {
    _currframe = nil;
    _prevframe = nil;
    FrameIdrawView* view = (FrameIdrawView*)GetViewer()->GetGraphicView();
    Iterator frame;
    view->First(frame);
    ((OverlayView*)view->GetView(frame))->Desensitize();
    view->Next(frame);
    if (view->Done(frame)) {
	view->First(frame);
	framenumstate()->framenumber(0, true);
    } else {
	framenumstate()->framenumber(1, true);
	Iterator i(frame);
	view->Next(i);
	while (!view->Done(i)) {
	    OverlayView* v = (OverlayView*)view->GetView(i);
	    v->Hide();
	    view->Next(i);
	}
    }
    SetFrame((FrameView*)view->GetView(frame));
    UpdateFrame(false);
}

void FrameEditor::Update() {
  ComEditor::Update();
}

void FrameEditor::UpdateFrame(boolean txtupdate) {
    FrameIdrawView *views = (FrameIdrawView*)GetViewer()->GetGraphicView();
    views->UpdateFrame(_currframe, _prevframe, _curr_other, _prev_other);
    _prev_other = _curr_other;
    UpdateText((OverlayComp*)GetFrame()->GetGraphicComp(), txtupdate);
    Iterator last;
    views->Last(last);
    frameliststate()->framenumber(views->Index(last)+1);
}

void FrameEditor::SetText() {
    GraphicComp* comp = GetFrame()->GetGraphicComp();
    ((OverlayComp*)comp)->SetAnnotation(TextEditor()->text());
    ((ModifStatusVar*)GetState("ModifStatusVar"))->SetModifStatus(true);
}

void FrameEditor::ClearText() {
    _texteditor->text("");
}

void FrameEditor::UpdateText(OverlayComp* comp, boolean update) {
    if (_texteditor) {
	const char* txt = comp->GetAnnotation();
	if (!txt)
	    txt = "";
	_texteditor->text(txt, update);
    }
}

FrameView* FrameEditor::GetFrame(int index) {
  if (index<0) 
    return _currframe;
  else if (index<_frameliststate->framenumber()) {
    FrameIdrawView* views = (FrameIdrawView*)GetViewer()->GetGraphicView();
    Iterator i;
    int count = 0;
    views->First(i);
    while (count++<index && !views->Done(i)) views->Next(i);
    return (FrameView*)views->GetView(i);
  } else
    return nil;
}
