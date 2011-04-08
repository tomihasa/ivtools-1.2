/*
 * Copyright (c) 1994-1997 Vectaport Inc.
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

#if !defined(grfunc_h)
#define _grfunc_h

#include <ComUnidraw/unifunc.h>

class CreateRectFunc : public UnidrawFunc {
public:
    CreateRectFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "grcomp=rect(x0,y0,x1,y1) -- create a rectangle"; }
};

class CreateLineFunc : public UnidrawFunc {
public:
    CreateLineFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "grcomp=line(x0,y0,x1,y1) -- create a line"; }
};

class CreateEllipseFunc : public UnidrawFunc {
public:
    CreateEllipseFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "grcomp=ellipse(x0,y0,r1,r2) -- create a rectangle"; }
};

class CreateTextFunc : public UnidrawFunc {  // doesn\'t work
public:
    CreateTextFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "grcomp=text(x0,y0 textstr) -- create a text string"; }
};

class CreateMultiLineFunc : public UnidrawFunc {
public:
    CreateMultiLineFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "grcomp=multiline(x0,y0[,x1,y1,...]) -- create a multiline"; }
};

class CreateOpenSplineFunc : public UnidrawFunc {
public:
    CreateOpenSplineFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "grcomp=openspline(x0,y0[,x1,y1,...]) -- create an open spline"; }
};

class CreatePolygonFunc : public UnidrawFunc {
public:
    CreatePolygonFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "grcomp=polygon(x0,y0[,x1,y1,...]) -- create a polygon"; }
};

class CreateClosedSplineFunc : public UnidrawFunc {
public:
    CreateClosedSplineFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "grcomp=closedspline(x0,y0[,x1,y1,...]) -- create a closed spline"; }
};

class FontFunc : public UnidrawFunc {
public:
    FontFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "font(fontnum) -- set current font from menu order"; }
};

class BrushFunc : public UnidrawFunc {
public:
    BrushFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "brush(brushnum) -- set current brush from menu order"; }
};

class PatternFunc : public UnidrawFunc {
public:
    PatternFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "pattern(patternnum) -- set current pattern from menu order"; }
};

class ColorFunc : public UnidrawFunc {
public:
    ColorFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "colors(fgcolornum bgcolornum) -- set current colors from menu order"; }
};

class SelectFunc : public UnidrawFunc {
public:
    SelectFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "select(grcomp [grcomp ...]) -- make these graphics the current selection"; }
};

class MoveFunc : public UnidrawFunc {
public:
    MoveFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "move(dx dy) -- move current selection"; }
};

class ScaleFunc : public UnidrawFunc {
public:
    ScaleFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "scale(dxflt dyflt) -- scale current selection"; }
};

class RotateFunc : public UnidrawFunc {
public:
    RotateFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "rotate(degflt) -- rotate current selection"; }
};

class PanFunc : public UnidrawFunc {
public:
    PanFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "pan(px py) -- pan viewer"; }
};

class PanUpSmallFunc : public UnidrawFunc {
public:
    PanUpSmallFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "smallpanup() -- small pan up"; }
};

class PanDownSmallFunc : public UnidrawFunc {
public:
    PanDownSmallFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "smallpandown() -- small pan down"; }
};

class PanLeftSmallFunc : public UnidrawFunc {
public:
    PanLeftSmallFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "smallpanleft() -- small pan left"; }
};

class PanRightSmallFunc : public UnidrawFunc {
public:
    PanRightSmallFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "smallpanright() - small pan right"; }
};

class PanUpLargeFunc : public UnidrawFunc {
public:
    PanUpLargeFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "largepanup() -- large pan up"; }
};

class PanDownLargeFunc : public UnidrawFunc {
public:
    PanDownLargeFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "largepandown() -- large pan down"; }
};

class PanLeftLargeFunc : public UnidrawFunc {
public:
    PanLeftLargeFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "largepanleft() -- large pan left"; }
};

class PanRightLargeFunc : public UnidrawFunc {
public:
    PanRightLargeFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "largepanright() -- large pan right"; }
};

class ZoomFunc : public UnidrawFunc {
public:
    ZoomFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "zoom(zoomflt) -- zoom by factor"; }
};

class ZoomInFunc : public UnidrawFunc {
public:
    ZoomInFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "zoomin() -- zoom-in by 2"; }
};

class ZoomOutFunc : public UnidrawFunc {
public:
    ZoomOutFunc(ComTerp*,Editor*);
    virtual void execute();
    virtual const char* docstring() { 
	return "zoomout() -- zoom-out by 2"; }
};

class TileFileFunc : public UnidrawFunc {
public:
    TileFileFunc(ComTerp*,Editor*);
    virtual void execute();
};

#endif /* !defined(_grfunc_h) */
