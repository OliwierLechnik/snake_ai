**Zabawa sieciami neuronowymi.**

  ##

Projekt składa się z 3 części:

  

 - snake - implementacja prostej turowej wersji gry snake

  

 - network - definicja klasy sieci neuronowej ktora docelowo nauczy się
   grać w snake'a
 - main - miejsce na trenowanie sieci algorytmem genetycznym. losowo
   poddajemy kilka set sieci roznym mutacją i sprawdzamy ktora najlepiej
   sobie radzi. najlepszą
   sieć potem kopiujemy tysięce razy, mutujemy i sprawdzamy jak sobie radzi i tak    dalej aż uzystamy jakiś konkretny wynik

  ##

proces uczenia będzie przeprowadzany na wielu wątkach a same decyzje jakie będzie podejmować sieć docelowo odbędą się na karcie graficznej