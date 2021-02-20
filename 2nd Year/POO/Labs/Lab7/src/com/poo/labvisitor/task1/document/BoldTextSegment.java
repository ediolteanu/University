package com.poo.labvisitor.task1.document;

import com.poo.labvisitor.task1.Visitors.DocumentVisitor;

public class BoldTextSegment extends TextSegment {
    public BoldTextSegment(String content) {
        super(content);
    }

    @Override
    public void accept(DocumentVisitor visitor) {
        visitor.visit(this);
    }

}
