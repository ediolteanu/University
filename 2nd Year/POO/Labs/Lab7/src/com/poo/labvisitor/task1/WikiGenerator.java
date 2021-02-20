package com.poo.labvisitor.task1;

import com.poo.labvisitor.task1.Visitors.DocumentVisitor;
import com.poo.labvisitor.task1.Visitors.DokuWikiVisitor;
import com.poo.labvisitor.task1.Visitors.MarkdownVisitor;
import com.poo.labvisitor.task1.document.TextSegment;

import java.util.List;

/**
 * Uses visitors to parse documents and provide dokuwiki and markdown outputs.
 */
public class WikiGenerator {

    private final List<TextSegment> textSegments;

    public WikiGenerator(List<TextSegment> textSegments) {
        this.textSegments = textSegments;
    }

    public StringBuilder getDokuWikiDocument() {
        // TODO apply dokuwiki visitor on the text segments
        DokuWikiVisitor visitor = new DokuWikiVisitor();
        for (TextSegment textSegment : textSegments) {
            textSegment.accept(visitor);
        }
        return visitor.getDocument();
    }
    public StringBuilder getDokuWikiDocument2() {
        // TODO apply dokuwiki visitor on the text segments
        DokuWikiVisitor visitor = new DokuWikiVisitor();
        for (TextSegment textSegment : textSegments) {
            textSegment.accept2(visitor);
        }
        return visitor.getDocument();
    }

    public StringBuilder getMarkdownDocument() {
        // TODO apply Markdown visitor on the text segments
        MarkdownVisitor visitor = new MarkdownVisitor();
        for (TextSegment textSegment : textSegments) {
            textSegment.accept(visitor);
        }
        return visitor.getDocument();
    }
}
