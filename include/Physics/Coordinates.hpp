#ifndef coordinates_hpp
#define coordinates_hpp

struct Coordinates
{
    int gridX, gridY;
    int offsetX, offsetY;

    Coordinates(int gx, int gy, int ox, int oy):
        gridX(gx),
        gridY(gy),
        offsetX(ox),
        offsetY(oy)
    {
    }

    bool operator==(const Coordinates& other)
    {
        return( (gridX == other.gridX) &&
                (gridY == other.gridY) &&
                (offsetX == other.offsetX) &&
                (offsetY == other.offsetY));
    }

    bool operator!=(const Coordinates& other)
    {
        return (!(*this == other));
    }
};

#endif //coordinate_hpp
