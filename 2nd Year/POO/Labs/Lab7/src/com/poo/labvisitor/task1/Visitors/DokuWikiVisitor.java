package com.poo.labvisitor.task1.Visitors;

import com.poo.labvisitor.task1.document.*;

public class DokuWikiVisitor implements DocumentVisitor {
    private StringBuilder document = new StringBuilder();

    @Override
    public void visit(ItalicTextSegment textSegment) {
        document.append("//").append(textSegment.getContent()).append("//");
    }

    @Override
    public void visit(BoldTextSegment textSegment) {
        document.append("**").append(textSegment.getContent()).append("**");
    }

    @Override
    public void visit(UrlSegment textSegment) {
        document.append("[[").append(textSegment.getContent()).append("|").append(textSegment.getDescription()).append("]]");
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
