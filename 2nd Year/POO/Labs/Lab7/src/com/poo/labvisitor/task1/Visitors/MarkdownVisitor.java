package com.poo.labvisitor.task1.Visitors;

import com.poo.labvisitor.task1.document.*;

public class MarkdownVisitor implements DocumentVisitor {
    private StringBuilder document = new StringBuilder();

    @Override
    public void visit(ItalicTextSegment textSegment) {
        document.append("_").append(textSegment.getContent()).append("_");
    }

    @Override
    public void visit(BoldTextSegment textSegment) {
        document.append("__").append(textSegment.getContent()).append("__");
    }

    @Override
    public void visit(UrlSegment textSegment) {
        document.append("[").append(textSegment.getDescription()).append("](").append(textSegment.getContent()).append(")");
    }

    @Override
    public void visit(PlainTextSegment textSegment) {
        document.append(textSegment.getContent());
    }

    @Override
    public void visit(TextSegment textSegment) {
        document.append(textSegment.getContent());
    }

    @Override
    public StringBuilder getDocument() {
        return document;
    }
}
