/*
 * Copyright (c) 2001 Scott E. Johnston
 * Copyright (c) 2000 IET Inc.
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
 * dot func supports a compound variable
 */

#if !defined(_dotfunc_h)
#define _dotfunc_h

#include <ComTerp/numfunc.h>

//: . (dot) operator, for compound variables | dotlst=dot(name) -- construct empty dottted pair list.
class DotFunc : public ComFunc {
public:
    DotFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "%s (.) makes compound variables | dotlst=dot(name) -- construct empty dotted pair list"; }

    CLASS_SYMID("DotFunc");
};

//: name returns name field of a dotted pair
//  attrname(attribute) returns name field of a dotted pair
class DotNameFunc : public ComFunc {
public:
    DotNameFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "%s(attribute) returns name field of a dotted pair"; }
};

//: value returns value field of a dotted pair
// attrval(attribute) returns value field of a dotted pair
class DotValFunc : public ComFunc {
public:
    DotValFunc(ComTerp*);

    virtual void execute();
    virtual const char* docstring() { 
      return "%s(attribute) returns value field of a dotted pair"; }
};
#endif /* !defined(_dotfunc_h) */

