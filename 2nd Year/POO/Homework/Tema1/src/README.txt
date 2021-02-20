Nume: Olteanu Eduard-Florin
Grupa: 324CD

POO - Tema1 - Sheriff of Nottingham

  In implementarea temei am pornit de la scheletul oferit. Citirea fiind deja
facuta am rezolvat doar problema cu API-ul. Apoi am creat o clasa abstracta 
care reprezenta structura jucatorilor. Clasa BasePlayer extinde clasa Player,
iar GreedyPlayer si BribedPlayer extind clasa BasePlayer deoarece au unele
parti asemanatoare in implementare.
  In clasa Game sunt implementate metodele ce tin de rularea jocului, metode
ce sunt apelate in Main, iar in clasa Constants am pus toate constantele de
care aveam nevoie pentru a nu avea magic numbers.
  I
n clasa Main sunt create lista de playeri si lista de carti  in functie de
input si apoi sunt apelate metodele din clasa Game in ordinea corespunzatoare
pentru a rula jocul.
  
  Pornind de la clasa Player am realizat structura celorlalte clase de playeri.
In clasa abstracta Player se afla getteri si setteri pentru valorile comune
tuturor jucatorilor dar si functiile drawCards si countGoodsById care sunt 
comune de asemenea. Functia drawCards trage 10 carti din lista initiala, iar
functia countGoodsById numara numarul de carti de acelasi fel in functie de
id-ul dat ca paramentru de pe taraba jucatorului.
  
  Clasa BasePlayer implementeaza cele 3 metode specifice fiecarei strategii:
createBag, inspectBags si toString. Metoda createBag ia ca parametru numarul 
rundei si aplica strategie de creare a sacului in functie de cerinta.
Astfel, pentru strategia Basic este creat un HashMap cu chei fiind toate 
tipurile de carti detinute de player in indrawnCards care reprezinta cartile pe
care le are in mana. De asemenea in HashMap ca si valoare este numarul de 
carti din tipul respectiv. Apoi se calculeaza numarul maxim de carti de acelasi
tip si se adauga toate cartile legale cu cantitatea maxima gasita in
highestFrequencyGoods. Daca aceasta lista este goala inseamna ca sunt numai
bunuri ilegale asa ca adaugam doar un bun ilegal, dar cel mai valoros.
Daca highestFrequencyGoods nu este goala se cauta bunurile cu profitul cel mai
mare si se adauga in lista maxProfitGoods. Daca este un singur bun in aceasta
lista se seteaza el ca fiind bunul declarat, daca nu se cauta bunul cu cel mai
mare id si se declara acela. La final se adauga toate bunurile in sac 
corespunzatoare bunului declarat.
  In metoda inspectBags sunt inspectati sacii tuturor jucatorilor deoarece
aceasta este strategia. Mai intai se verifica daca seriful poate verifica
(daca are mai mult de 16 bani) - daca nu, toate bunurile trec. Daca are destui
bani, bunurile ilegale sau nedeclarate gasite se adauga in lista 
confiscatedGoods. Daca aceasta este goala inseamna ca jucatorul a fost cinstit
si toate bunurile trec, iar seriful plateste penalty. Daca nu jucatorul
plateste penalty. La sfarsit bunurile care au ramas in sac sunt trecute 
in lista merchantMarketStall care reprezinta taraba, iar la finalul pachetului
de carti sunt adaugate bunurile confiscate. De asemenea seriful basic nu 
accepta mita.
  Metoda toString este suprascrisa pentru a afisa forma ceruta pentru fiecare
player.

  Clasa GreedyPlayer extinde clasa BasePlayer. In metoda createBag este apelat
super pentru a crea sacul ca jucatorul cu strategia basic, dar apoi se verifica
daca numarul rundei este par pentru a incerca sa adauge cel mai profitabil bun
ilegal. Daca nu exista nu se adauga. 
  Metoda inspectBags, este ca cea BasePlayer, doar ca atunci cand un player
ofera mita, aceasta este acceptate si toate bunurile sunt puse in
merchantMarketStall, fara a fi verificate.
  Metoda toString este suprascrisa pentru a afisa forma ceruta pentru fiecare
player.
  
  Clasa BribedPlayer este si ea extindere a clasei BasePlayer deoarece atunci 
cand verifica stanga si dreapta seriful Bribed este ca un serif Basic.
  Prima metoda, getIllegalGoodsNo, numara bunurile ilegale din lista data ca
parametru pentru a verifica in metoda createBag daca exista bunuri ilegale ce
pot fi adaugate, dar si pentru a decide ce suma sa puna la mita in functie de
numarul de bunuri ilegale din sac.
  Metoda createBag creeaza sacul dupa regulile strategiei. Cat timp sacul nu 
este plin si mai sunt carti se adauga cel mai valoros bun in sac. Daca sunt
mai multe se adauga acela cu id-ul mai mare. Daca penalty-ul pe care ar trebui
sa il plateasca daca ar fi verificat este mai mare decat banii pe care ii are,
bunul este scos din sac si din cartile din mana. Apoi se seteaza mita in
functie de numarul de bunuri ilegale. Daca nu are bunuri ilegale, se apeleaza
super pentru a crea sacul dupa strategia basic.
  Metoda getPlayersToInspect returneaza o lista cu id-urile jucatorilor care 
trebuie inspectati de seriful Bribed.
  Metoda inspectBags creeaza 2 liste, una cu jucatorii care trebuie inspectati
si una cu cei de la care incearca sa ia mita. Apoi apeleaza super.inspectBags
pe lista de jucatori inspectati pentru a ii inspecta ca seriful basic, iar 
apoi ia mita de la cei care au mita de oferit, si pe tot ceilalti ii trece mai
departe.
  Metoda toString este suprascrisa pentru a afisa forma ceruta pentru fiecare
player.

  In clasa Game sunt gasiti mai intai constructorul si getteri si setteri.
Apoi, in metoda addIllegalGoodsBonuses este parcursa lista de playeri, pentru
fiecare player este parcursa lista de iteme de pe taraba, iar pentru fiecare
bun ilegal de pe taraba sunt adaugate toate cartile de la bonus in lista 
bonusGoods, care este adaugata apoi in totalitate inapoi pe taraba.
  In metoda sellGoods este parcursa lista de playeri si pentru fiecare player
este calculat profitul pe care il aduc bunurile de pe taraba, care impreuna cu
banii ramasi se adauga la scor.
  In metoda addKingQueenBonuses sunt parcurse id-urile de la 0 la 9, adica cele
ale bunurilor legale. Pentru fiecare bun legal este creat un hashmap cu 
jucatorul si cantitatea de bunuri de la tipul curent. Apoi este parcursa lista 
de jucatori si sunt cautati primii doi jucatori cu cele mai multe bunuri in
functie de valoarea din hashmap. La final se adauga bonusurile corespunztoare
la scor si acesta reprezinta scorul final.
  In metoda startGame are loc jocul propriu-zis cu etapele lui. Astfel, jocul
ruleaza cate runde sunt si cate subrunde sunt, iar apoi pentru fiecare player
cauta daca acesta este serif, daca nu trage carti si creeaza sacul, iar apoi
seriful inspecteaza toti sacii.
  Ultima metoda, createRanking foloseste clasa statica PlayerComparator pentru
a crea si afisa clasamentul in functia de scor.

