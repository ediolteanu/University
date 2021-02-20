Nume: Olteanu Eduard-Florin
Grupa: 324CD

POO - Tema1 - Sheriff of Nottingham

  In implementarea temei am pornit de la scheletul oferit. Citirea fiind deja
facuta am rezolvat doar problema cu API-ul. Apoi am creat o clasa abstracta 
care reprezenta structura jucatorilor. Clasa BasePlayer extinde clasa Player,
iar GreedyPlayer si BribedPlayer exting clasa BasePlayer deoarece au unele
parti asemanatoare in implementare.
  In clasa Game sunt implementate metodele ce tin de rularea jocului, metode
ce sunt apelate in Main, iar in clasa Constants am pus toate constantele de
care aveam nevoie pentru a nu avea magic numbers.
