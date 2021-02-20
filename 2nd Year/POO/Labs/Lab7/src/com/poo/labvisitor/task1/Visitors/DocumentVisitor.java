package com.poo.labvisitor.task1.Visitors;

import com.poo.labvisitor.task1.document.*;

public interface DocumentVisitor {
    public void visit(ItalicTextSegment textSegment);
    public void visit(BoldTextSegment textSegment);
    public void visit(UrlSegment textSegment);
    public void visit (PlainTextSegment textSegment);
    public void visit(TextSegment textSegment);
    public StringBuilder getDocument();
}
