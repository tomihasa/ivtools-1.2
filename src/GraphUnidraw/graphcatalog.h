/*
 * Copyright (c) 1994-1999 Vectaport Inc.
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

/* 
 * GraphCatalog - can read and write components in dspcom commands
 * (or idraw postscript).
 */

#ifndef grcatalog_h
#define grcatalog_h

#include <OverlayUnidraw/ovcatalog.h>

//: catalog for read/write of graphdraw documents.
class GraphCatalog : public OverlayCatalog{
public:
    GraphCatalog(const char*, Creator*);

    virtual boolean Save(Component*, const char*);
    // pass to OverlayCatalog::Save.
    virtual boolean Retrieve (const char* path, Component*&);
    // read component tree from 'path', saving node and edge connectivity
    // information in tables until done, then reconnect graph.
    void SetImport(boolean);
    // set flag that indicates read is for import instead of an open.

protected:
    boolean _import;

};

inline void GraphCatalog::SetImport(boolean v) { _import = v; }

#endif
