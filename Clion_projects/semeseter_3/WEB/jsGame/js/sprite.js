/*class Sprite {
    constructor({position, imageSrc}) {
        this.position = position
        this.image = new Image()
        this.image.src = imageSrc
        this.isImageLoaded = false
        this.image.onload = ()=>{
            console.log("image loaded")
            this.width = this.image.width
            this.height = this.image.height
            this.isImageLoaded = true

        }
    }

    draw() {
      /* if (!this.image.width || !this.image.height){
            console.log("if abfrage angeschlagen")
            //c.drawImage(this.image, this.position.x, this.position.y);
            return;
        }*/

       /* if(!this.isImageLoaded){
            console.log("not loaded yet")
            return
        }*/

        //c.drawImage(this.image, this.position.x, this.position.y);
   // }

    //update() {
        //this.draw();
   // }
//}
/*
class Sprite {
    constructor({position, imageSrc, frameRate = 1, frameBuffer = 12, scale = 1}) {
        this.position = position
        this.image = new Image()

        if (!imageSrc) {
            console.error("Kein Bildpfad übergeben!")
            return; // Verhindert den Fehler
        }

        this.image.src = imageSrc
        this.frameRate = frameRate
        this.currentFrame = 0
        this.frameBuffer = frameBuffer
        this.elapsedFrames = 0
        this.scale = scale

        this.image.onload = () => {
            this.width = (this.image.width / this.frameRate) * this.scale
            this.height = this.image.height * this.scale;
            console.log("Bild geladen:", imageSrc);
        };
        this.image.onerror = () => {
            console.error("Fehler beim Laden des Bildes:", imageSrc)
        };
    }

    draw() {
        if (!this.image.complete) {
            console.log("Bild wird noch geladen...")
            return;
        }

        const cropbox = {
            position: {
                x: this.currentFrame * (this.image.width/this.frameRate),
                y:0
            },
            width: this.image.width / this.frameRate,
            height: this.image.height,
        }

        c.drawImage(this.image,
            cropbox.position.x,
            cropbox.position.y,
            cropbox.width,
            cropbox.height,
            this.position.x,
            this.position.y,
            this.width, // this.frameRate,
            this.height
        )

    }

    update() {
        this.draw();
        this.updateFrames()
    }

    updateFrames(){
        this.elapsedFrames++
        if(this.elapsedFrames % this.frameBuffer === 0){
            if(this.currentFrame === this.frameRate -1){
                this.currentFrame = 0
            }
            this.currentFrame++
        }

    }

}


 */

class Sprite {
    constructor({
                    position,
                    imageSrc,
                    frameRate = 1,
                    frameBuffer = 3,
                    scale = 1,
                }) {
        this.position = position
        this.scale = scale
        this.loaded = false
        this.image = new Image()
        this.image.onload = () => {
            this.width = (this.image.width / this.frameRate) * this.scale
            this.height = this.image.height * this.scale
            this.loaded = true
        }
        this.image.src = imageSrc
        this.frameRate = frameRate
        this.currentFrame = 0
        this.frameBuffer = frameBuffer
        this.elapsedFrames = 0
    }

    draw() {
        if (!this.image) return

        const cropbox = {
            position: {
                x: this.currentFrame * (this.image.width / this.frameRate),
                y: 0,
            },
            width: this.image.width / this.frameRate,
            height: this.image.height,
        }

        c.drawImage(
            this.image,
            cropbox.position.x,
            cropbox.position.y,
            cropbox.width,
            cropbox.height,
            this.position.x,
            this.position.y,
            this.width,
            this.height
        )
    }

    update() {
        this.draw()
        this.updateFrames()
    }

    updateFrames() {
        this.elapsedFrames++

        if (this.elapsedFrames % this.frameBuffer === 0) {
            if (this.currentFrame < this.frameRate - 1) this.currentFrame++
            else this.currentFrame = 0
        }
    }
}

class Ground {
    constructor() {
        this.x = 0;
        this.y = canvas.height - 30;
        this.width = canvas.width;
        this.height = 50;
        this.color = "green";
    }

    draw() {
        c.beginPath();
        c.rect(this.x, this.y, this.width, this.height);
        c.fillStyle = this.color;
        c.fill();
    }

}
