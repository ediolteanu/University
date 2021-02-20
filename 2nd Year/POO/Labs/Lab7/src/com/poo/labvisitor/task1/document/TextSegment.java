package com.poo.labvisitor.task1.document;

import com.poo.labvisitor.task1.Visitors.DocumentVisitor;

/**
 * Represents a text segment of a document that needs to be parsed.
 */
public abstract class TextSegment {
    private String content;

    TextSegment(String content) {
        this.content = content;
    }

    public String getContent() {
        return content;
    }

    // TODO add method for applying the visitor
    public abstract void accept(DocumentVisitor visitor);
    public void accept2(DocumentVisitor visitor) {
        visitor.visit(this);
    }

}
