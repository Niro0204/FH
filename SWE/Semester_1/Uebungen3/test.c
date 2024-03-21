
// Define a struct for RGB color
typedef struct {
    int red;
    int green;
    int blue;

} RGBColor;


int main() {
    setup();
    
    
    RGBColor colors[] = {
        {1, 0, 0},  // Red
        {0, 1, 0},  // Green
        {0, 0, 1},  // Blue
        {1, 1, 0},  // Yellow
        {1, 0, 1},  // Magenta
        {0, 1, 1},  // Cyan
        {1, 1, 1},  // White
        {0, 0, 0}   // Off
    };

    int numColors = sizeof(colors) / sizeof(colors[0]);

    for (int i = 0; i < numColors; i++) {
        setColor(colors[i]);
        delay(2000); 
    }



    for(int i=0;i<8;i++){

        

    }

    return 0;
}