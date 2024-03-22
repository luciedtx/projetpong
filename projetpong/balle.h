#pragma once
void screenLimits() {
    // bound balle if it touched the screen border
    if (y <= 0 || y + size >= 600) { dy = -dy; }

    // bound both rectangles if it touched the screen border
    if (yRectLeft <= 0 || yRectLeft + widthRectLeft >= 500) { dyRectLeft = -dyRectLeft; }

    if (yRectRight <= 0 || yRectRight + widthRectRight >= 500) { dyRectRight = -dyRectRight; }


}

void stopBalle() {
    // vérifier si la balle est à l'intérieur des limites de l'écran
    if (x >= 0 && x + size <= 800) {

        // mise à jour de la position de la balle
        x += dx;
        y += dy;

        // vérifier si la balle est sortie de l'écran
        if (x < 10 || x + size > 790) {
            if (dx > 0)
            {
                dx = 5;
                dy = 5;
            }
            if (dx < 0)
            {
                dx = -5;
                dy = -5;
            }
            x = initX;
            y = initY;
            // arrêter le mouvement de la balle
        }
    }
}

