/*
 * Copyright (c) 1990, 1991 Stanford University
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Stanford not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  Stanford makes no representations about
 * the suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * STANFORD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
 * IN NO EVENT SHALL STANFORD BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Transformation commands.
 */

#ifndef unidraw_commands_transforms_h
#define unidraw_commands_transforms_h

#include <Unidraw/Commands/command.h>

#include <IV-2_6/_enter.h>

//: move command
// <a href=../man3.1/transforms.html>man page</a>
class MoveCmd : public Command {
public:
    MoveCmd(ControlInfo*, float = 0, float = 0);
    MoveCmd(Editor* = nil, float = 0, float = 0);

    void GetMovement(float&, float&);

    virtual Command* Copy();
    virtual void Read(istream&);
    virtual void Write(ostream&);
    virtual ClassId GetClassId();
    virtual boolean IsA(ClassId);
protected:
    float _dx, _dy;
};

//: scale command
// <a href=../man3.1/transforms.html>man page</a>
class ScaleCmd : public Command {
public:
    ScaleCmd(ControlInfo*, float = 1, float = 1, Alignment = Center);
    ScaleCmd(Editor* = nil, float = 1, float = 1, Alignment = Center);

    void GetScaling(float&, float&);
    Alignment GetAlignment();

    virtual Command* Copy();
    virtual void Read(istream&);
    virtual void Write(ostream&);
    virtual ClassId GetClassId();
    virtual boolean IsA(ClassId);
protected:
    float _sx, _sy;
    Alignment _align;
};

inline Alignment ScaleCmd::GetAlignment () { return _align; }

//: rotate command
// <a href=../man3.1/transforms.html>man page</a>
class RotateCmd : public Command {
public:
    RotateCmd(ControlInfo*, float = 0);
    RotateCmd(Editor* = nil, float = 0);

    float GetRotation();

    virtual Command* Copy();
    virtual void Read(istream&);
    virtual void Write(ostream&);
    virtual ClassId GetClassId();
    virtual boolean IsA(ClassId);
protected:
    float _angle;
};

inline float RotateCmd::GetRotation () { return _angle; }

class Transformer;

//: transform command
// <a href=../man3.1/transforms.html>man page</a>
class TransformCmd : public Command {
public:
    TransformCmd(ControlInfo*, Transformer* = nil);
    TransformCmd(Editor* = nil, Transformer* = nil);

    Transformer* GetTransformer();

    virtual Command* Copy();
    virtual ClassId GetClassId();
    virtual boolean IsA(ClassId);
protected:
    Transformer* _t;
};

#include <IV-2_6/_leave.h>

#endif
