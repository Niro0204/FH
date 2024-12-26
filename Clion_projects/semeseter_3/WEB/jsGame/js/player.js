
const platforms = [
    { position: {x: 0, y: 400} , width: 700, height: 20 },
    { position: {x: 300, y: 700}, width: 400, height: 20 },
    { position: {x: 670, y: 550}, width: 500, height: 20 },
    { position: {x: 1250, y: 400}, width: 700, height: 20 },
    { position: {x: 800, y: 250}, width: 350, height: 20 },
    { position: {x: 1100, y: 700}, width: 600, height: 20 }]


class Player extends Sprite {
    constructor({position, imageSrc, frameRate, frameBuffer, scale}) {
        super({ position, imageSrc, frameRate, frameBuffer, scale})
        //this.width = 25;
        this.height = 50;
        //this.color = "red"
        this.isJumping = false
        this.onPlatform = false
        this.onGround = true
        //this.position = positiondw
        this.velocity = { x: 0, y: 1 }

        this.hitbox = {
            position: {
                x: 0,
                y: 0
            },
            width: 30,
            height: 73,
        }

        this.collisions = platforms
    }

    update() {

        this.updateFrames()
        this.updateHitbox()
        //this.collisionCheck()

        console.log("PLAYER x: ", this.position.x, " y: ", this.position.y)

        // draws the image
        //c.fillStyle = "rgba(0,255,0)"
        //c.fillRect(this.position.x,this.position.y,this.width,this.height)

        // draws the hitbox
        c.fillStyle = "rgb(255,0,0)"
        c.fillRect(this.hitbox.position.x, this.hitbox.position.y, this.hitbox.width, this.hitbox.height)


        this.draw()

        this.position.x += this.velocity.x
        this.applyGravity()
        this.updateHitbox()

        //this.collisionCheck()


        console.log("PLATFORM",this.onPlatform)


        this.updateHitbox()
        //this.collisionCheck()


        if (this.position.y + this.height >= canvas.height - 30) {
            this.position.y = canvas.height - 30 - this.height
            this.velocity.y = 0
            this.isJumping = false
            this.onGround = true
        }
        else{
            this.onGround = false
        }

        platforms.forEach(platform => {
            this.platformCollision(this, platform)
        });






/*
        let isStandingOnPlatform = false;

        platforms.forEach(platform => {
            if (platformCollision(this, platform)) {
                isStandingOnPlatform = true;
            }
        });

        this.onPlatform = isStandingOnPlatform;

// Wenn der Spieler nicht auf einer Plattform steht, fällt er weiter
        if (!this.onPlatform) {
            this.isJumping = true;
        }

*/




    }


    applyGravity() {
        console.log("ON PLATFORM GRAVITY: ", this.onPlatform)
        if(this.onPlatform === false)
        this.velocity.y += GRAVITY
        this.position.y += this.velocity.y
    }
/*
   applyGravity() {
        if (!this.onPlatform) {
            this.velocity.y += GRAVITY;
            console.log("SCHWERKRAFT AN!!")
            this.position.y += this.velocity.y;
            // Falls der Spieler in der Luft ist, wird Schwerkraft angewendet
        }

    }*/

    //Bester Ansatz
/*
    applyGravity() {
        if (!this.onPlatform) {
            this.velocity.y += GRAVITY;
            this.position.y += this.velocity.y;
        }


       // this.collisionCheck(); // Plattform prüfen nach Bewegung
    }*/

/*
    applyGravity() {
       //if(!this.onPlatform ){
           this.velocity.y += GRAVITY
           this.position.y += this.velocity.y
       //}

    }*/






    /*
        collisionCheck() {
            for(let i = 0; i <= this.collisions.length -1; i++){
               const platform = this.collisions[i]
                console.log("PLATFORM Y: ", platform.y)
                if(
                    collision({
                        object1: this.hitbox,
                        object2: platform})
                ){
                    if(this.velocity.y > 0){
                        console.log("COLLISION DETECTET!!!!!!!!!")

                        this.velocity.y = 0
                       //const offset = this.hitbox.position.y - this.position.y + this.hitbox.height

                       // this.position.y = platform.position.y - offset - 0.01
                        this.onPlatform = true

                        //this.position.y= platform.y - this.height
                    }


                }
            }
        }
        */


    //Das war besser:
    /*
    collisionCheck() {
        this.onPlatform = false; // Zuerst annehmen, dass der Spieler nicht auf einer Plattform ist
        for (let i = 0; i < this.collisions.length; i++) {
            const platform = this.collisions[i];

            if (collision({ object1: this.hitbox, object2: platform })) {
                if (this.velocity.y > 0) {  // Wenn der Spieler nach unten fällt
                    console.log("COLLIOSION DETECTET!!!!!!!!!!!!!!!!!!!!!!!")
                    this.velocity.y = 0;  // Stoppe das Fallen
                    this.position.y = platform.position.y - this.hitbox.height;  // Setze den Spieler genau auf die Plattform
                    this.onPlatform = true;  // Der Spieler steht nun auf einer Plattform
                    this.isJumping = false;  // Das Springen ist jetzt beendet
                    break;  // Keine weitere Kollisionserkennung nötig, da der Spieler auf der Plattform steht
                }
            }
        }
    }*/

    // auch nicht schlecht:
    /*
    collisionCheck() {
        let isOnPlatform = false; // Variable für den aktuellen Durchlauf

        for (let i = 0; i < this.collisions.length; i++) {
            const platform = this.collisions[i];

            if (collision({ object1: this.hitbox, object2: platform })) {
                if (this.velocity.y > 0) {
                    console.log("COLLIOSION DETECTET!!!!!!!!!!!!!!!!!!!!!!!")
                    this.velocity.y = 0;
                   // this.position.y = platform.position.y - this.hitbox.height;
                   // const offset =
                   //     this.hitbox.position.y - this.position.y + this.hitbox.height

                    const offset = this.hitbox.position.y - this.position.y;
                    this.position.y = platform.position.y - this.hitbox.height + offset;


                    this.position.y = platform.position.y - offset - 0.01
                    isOnPlatform = true; // Spieler steht auf der Plattform
                    this.isJumping = false;
                    break;
                }
            }
        }

        this.onPlatform = isOnPlatform; // Nur nach Schleife aktualisieren
    }*/
/*
    collisionCheck(i) {
        this.onPlatform = false;

        //for (let i = 0; i < this.collisions.length ; i++) {
            const platform = this.platforms[i];

            const isCollidingVertically =
                this.hitbox.position.y + this.hitbox.height === platform.position.y &&
                this.hitbox.position.y <= platform.position.y + platform.height;

            const isCollidingHorizontally =
                this.hitbox.position.x + this.hitbox.width > platform.position.x &&
                this.hitbox.position.x < platform.position.x + platform.width;

            if (isCollidingVertically && isCollidingHorizontally) {
                // Spieler landet auf Plattform
                if (this.velocity.y > 0) {
                    console.log("COLLISION!!!!!!!!!!!!!!")
                    this.position.y = platform.position.y - this.height;
                    this.velocity.y = 0;
                    this.onPlatform = true;
                    this.isJumping = false;
                    //break;
                }
            }
       // }
    }*/
/*
    collisionCheck() {
        this.onPlatform = false;

        for (let i = 0; i < this.collisions.length; i++) {
            const platform = this.collisions[i];
            console.log(`Checking platform at x: ${platform.position.x}, y: ${platform.position.y}`);

            const isCollidingVertically =
                this.hitbox.position.y + this.hitbox.height === platform.position.y &&
                this.hitbox.position.y <= platform.position.y + platform.height;

            const isCollidingHorizontally =
                this.hitbox.position.x + this.hitbox.width > platform.position.x &&
                this.hitbox.position.x < platform.position.x + platform.width;

            if (isCollidingVertically && isCollidingHorizontally) {
                console.log("COLLISION!!!!!!!!!!!!!!");
                this.position.y = platform.position.y - this.height;
                this.velocity.y = 0;
                this.onPlatform = true;
                this.isJumping = false;
                break; // Du könntest testen, was passiert, wenn du es entfernst
            }
        }
    }*/

    platformCollision(player, platform) {
        const pBottom = player.hitbox.position.y + player.hitbox.height
        const pTop = player.hitbox.position.y
        const platformTop = platform.position.y
        const platformBottom = platform.position.y + platform.height
        const pRight = player.hitbox.position.x + player.hitbox.width
        const pLeft = player.hitbox.position.x

        const platformLeft = platform.position.x
        const platformRight = platform.position.x + platform.width

        if (
            pBottom <= platformTop && // Spieler berührt die Plattform
            pBottom + player.velocity.y >= platformTop && // Spieler bewegt sich Richtung Plattform
            player.hitbox.position.x + player.hitbox.width > platform.position.x && // Spieler ist horizontal über der Plattform
            player.hitbox.position.x < platform.position.x + platform.width // Spieler ist horizontal innerhalb der Plattform
        ) {

            console.log("COLLISION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
            player.onPlatform = true
            this.position.y = platformTop - this.height;
            player.velocity.y = 0;
            player.isJumping = false;
            player.onGround = false;

            console.log("ON PLATFORM: ", this.onPlatform)

        }
        else{
            this.onGround = true;
            this.onPlatform = false
        }

        if (!player.onGround) {
            player.isJumping = true;
        }
    }





    updateHitbox(){
        this.hitbox = {
            position: {
                x: this.position.x + 50,
                y: this.position.y + 55
            },
            width: 30,
            height: 73,
        }
    }


/*
    jump() {
        if (this.isJumping === false && (this.onGround === true || this.onPlatform === true)) {
            console.log("did we get here")
            this.velocity.y = -15
            this.isJumping = true
        }

        console.log("jumping logic",( this.isJumping === false && (this.onGround === true || this.onPlatform === true)))

    }

*/

/*
    jump(){
        if(!this.isJumping){
            this.velocity.y = -4
            this.isJumping = true
        }
    }
*/
   // jump() {
       //if (!this.isJumping /*&& (this.onGround || this.onPlatform)*/) {
           /* console.log("Springen...");
            this.velocity.y = -15; // Setzt eine Sprungkraft
            this.isJumping = true;*/
       // }
  //  }


    jump(){
        if(this.isJumping === false){
            this.velocity.y = -15
            this.isJumping = true
        }
    }

}
