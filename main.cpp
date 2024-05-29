#include <iostream>
#include "Galois.hpp"
#include "Koder.h"
#include "Dekoder.h"
#include <vector>

int main() {


    Galois msg = Galois(std::vector<int>{1, 2, 3, 4, 5}, 4);
    Koder code;
    Dekoder decode;
    if(false)
    {


    std::cout << "Wiadomosc" << std::endl;
    msg.wyswietl();


    Galois coded = code.codePolynomial(msg);
    std::cout << std::endl;
    std::cout << "Zakodowana wiadomosc" << std::endl;
    coded.wyswietl();
    std::cout << std::endl;

    Galois received = coded;
    received.wspolczynniki[8] = 255;

    received.wspolczynniki[6] = 255;

    Galois syndrom = decode.syndrom(received);

    std::cout << "Syndrom" << std::endl;
    syndrom.wyswietl();

    Galois repaired = decode.singlerepair(received);

    std::cout << std::endl;
    std::cout << "Naprawiony" << std::endl;
    repaired.wyswietl();

    repaired.Xdodaj(coded);

    std::cout << std::endl;
    std::cout << "XOR" << std::endl;
    repaired.wyswietl();
}


std::string aa = code.code("Defensive secretions\n"
                           "Typical for the ancient beetle suborder Adephaga to which they belong, they have paired pygidial glands in the lower back of the abdomen. These are well developed in ground beetles, and produce noxious or even caustic secretions used to deter would-be predators. In some, commonly known as bombardier beetles, these secretions are mixed with volatile compounds and ejected by a small combustion, producing a loud popping sound and a cloud of hot and acrid gas that can injure small mammals, such as shrews, and is liable to kill invertebrate predators outright.\n"
                           "\n"
                           "To humans, getting \"bombed\" by a bombardier beetle is a decidedly unpleasant experience. [citation needed] This ability has evolved independently twice, as it seems, in the flanged bombardier beetles (Paussinae), which are among the most ancient ground beetles, and in the typical bombardier beetles (Brachininae), which are part of a more \"modern\" lineage. The Anthiini, though, can mechanically squirt their defensive secretions for considerable distances and are able to aim with a startling degree of accuracy; in Afrikaans, they are known as oogpisters (\"eye-pissers\"). In one of the very few known cases of a vertebrate mimicking an arthropod, juvenile Heliobolus lugubris lizards are similar in color to the aposematic oogpister"
                           " beetles, and move in a way that makes them look surprisingly similar to the insects at a casual glance.[6]\n"
                           "\n"
                           "A folk story claims that Charles Darwin once found himself on the receiving end of a bombardier beetle's attack, based on a passage in his autobiography.[7][8] Darwin stated in a letter to Leonard Jenyns that a beetle had attacked him on that occasion, but he did not know what kind:\n"
                           "\n"
                           "A Cychrus rostratus once squirted into my eye & gave me extreme pain; & I must tell you what happened to me on the banks of the Cam in my early entomological days; under a piece of bark I found two carabi (I forget which) & caught one in each hand, when lo & behold I saw a sacred Panagæus crux major; I could not bear to give up either of my Carabi, & to lose Panagæus was out of the question, so that in despair I gently seized one of the carabi between my teeth, when to my unspeakable disgust & pain the little inconsiderate beast squirted his acid down my throat & I lost both Carabi & Panagæus![9]""Reynoutria japonica, synonyms Fallopia japonica and Polygonum cuspidatum, is a species of herbaceous perennial plant in the knotweed ""and buckwheat family Polygonaceae.[1][2] Common names include Japanese knotweed[2] and Asian knotweed.[3] It is native to East ""Asia in Japan, China and Korea. In North America and Europe, the species has successfully established itself in numerous habitats, ""and is classified as a pest and invasive species in several countries.[2][4][5][6] The plant is popular with be"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     "ekeepers, and"" its ""young stems are"" edible, making it"" an increasingly popular foraged vegetable with a flavour described as lemony rhubarb.[7]\n"
                           "\n"
                           "Description\n"
                           "The flowers are small, cream or white, produced in erect racemes 6–15 cm (2+1⁄2–6 in) long in late summer and early autumn. Japanese knotweed has hollow stems with distinct raised nodes that give it the appearance of bamboo, though it is not related. While stems may reach a maximum height of 3–4 m (10–13 ft) each growing season, it is typical to see much smaller plants in places where they sprout through cracks in the pavement or are repeatedly cut down. The leaves are broad oval with a truncated base, 7–14 cm (3–5+1⁄2 in) long and 5–12 cm (2–4+1⁄2 in) broad,[8] with an entire margin. New leaves of Reynoutria"
                           " japonica are dark red and 1 to 4 cm (1⁄2 to 1+1⁄2 in) long; young leaves are green and rolled back with dark red veins; "
                           "leaves are green and shaped like a heart flattened at the base, or a shield, and are usually around 12 cm (5 in) long.\n"
                           "\n"
                           "Mature R. japonica forms 2-to-3-metre-tall (6+1⁄2 to 10 ft), dense thickets. Leaves shoot from the stem nodes alternately in a zigzag pattern. Plants that are immature or affected by mowing and other restrictions have much thinner and shorter stems than mature stands, and are not hollow.[9]");
    std::string bb=decode.decode(aa);

    std::cout<<aa<<std::endl;
    std::cout<<bb<<std::endl;


    return 0;
}
