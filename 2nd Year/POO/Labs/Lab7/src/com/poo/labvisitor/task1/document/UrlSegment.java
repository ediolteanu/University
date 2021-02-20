package com.poo.labvisitor.task1.document;

import com.poo.labvisitor.task1.Visitors.DocumentVisitor;

public class UrlSegment extends TextSegment {
    private String description;
    public UrlSegment(String url, String description) {
        super(url);
        this.description = description;
    }

    public String getDescription() {
        return description;
    }

    public void accept(DocumentVisitor visitor) {
        visitor.visit(this);
    }
}
