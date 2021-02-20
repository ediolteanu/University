package heroes;

import angels.Visitor;

public interface Visitable {
    void accept(Visitor visitor);
}
