function collision({object1,object2}){

    console.log("COLLISION FUNKTION OBJEKT 1: ", object1.position.y + object1.height)
    console.log("COLLISION FUNKTION OBJECT 2: ",object2.y)

    const pBottom = object1.position.y + object1.height;
    const pTop = object1.position.y;
    const platformTop = object2.position.y;
    const platformBottom = object2.position.y + object2.height;
    const pRight = object1.position.x + object1.width;
    const pLeft = object1.position.x;

    const platformLeft = object2.position.x;
    const platformRight = object2.position.x + object2.width;

    return (
      /* object1.position.y + object1.height <= object2.position.y &&
        object1.position.y <= object2.position.y + object2.height &&
        object1.position.x <= object2.position.x + object2.width &&
        object1.position.x + object1.width >= object2.position.x*/

        pBottom <= platformTop && // Spieler berührt die Plattform
        pBottom + player.velocity.y >= platformTop && // Spieler bewegt sich Richtung Plattform
        object1.position.x + object1.width > object2.position.x && // Spieler ist horizontal über der Plattform
        object1.position.x < object2.position.x + object2.width

    )
}