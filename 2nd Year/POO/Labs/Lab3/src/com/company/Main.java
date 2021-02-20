package com.company;

public class Main {

    public static void main(String[] args) {
	Lindt l1 = new Lindt("Vanilla", "Germany",1,2,3);
	Lindt l2 = new Lindt("Chocolate", "Romania", 2, 2 ,4);
	Lindt l3 = new Lindt("Vanilla", "Germany",1,2,3);
	System.out.println(l1.equals(l2));
	System.out.println(l1.equals(l3));

    CandyBag cadou = new CandyBag();
    ChocArmor c1 = new ChocArmor("Dark Chocolate", "Brasil", 2);
    ChocArmor c2 = new ChocArmor("Orange", "Sweden", 4);
    Baravelli b1 = new Baravelli("Banana","Egipt",2,3);
    Baravelli b2 = new Baravelli("Raspberry", "France", 1,2);
    cadou.addCandy(c1);
    cadou.addCandy(c2);
    cadou.addCandy(b1);
    cadou.addCandy(b2);
    cadou.addCandy(l1);
    cadou.addCandy(l2);
    cadou.addCandy(l3);

    Area cartier = new Area(cadou, 4,"Strada Ulitei");
    cartier.getBirthdayCard();
    }
}
