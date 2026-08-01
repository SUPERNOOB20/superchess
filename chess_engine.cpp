enum PIECE_TYPE {
    EMPTY,   // 0
    PAWN,    // 1
    KNIGHT,  // 2
    ROOK,    // 3
    BISHOP,  // 4
    QUEEN,   // 5
    KING    // 6
};


enum COLOUR {
    WHITE,      // true
    BLACK       // false
};


// Material value (https://en.wikipedia.org/wiki/Chess_piece_relative_value).
enum PIECE_VALUE {
    PAWN_VALUE = 1,
    KNIGHT_VALUE = 3,
    BISHOP_VALUE = 3,
    ROOK_VALUE = 5,
    QUEEN_VALUE = 9,
    KING_VALUE = 9999       // "infinite" value.
};


#include <array>
typedef std::array<unsigned short int, 2> tile_ID;




class Piece{
  private:  // Attributes.
    tile_ID tile_number;
    short int material_value;                   // pawn_material_value =  ....    queen_material_value =  ....
    unsigned short int piece_type;
    bool colour;

    
  public:   // Methods & Interface.

    // Constructor.
    Piece(tile_ID my_tile_number, short int my_material_value, unsigned short int my_piece_type, bool my_colour){
        tile_number = my_tile_number;
        material_value = my_material_value;
        piece_type = my_piece_type;
        colour = my_colour;
    }


    // Getters & Setters.
    short int get_material_value() { return material_value; }
    void set_material_value(short int new_material_value) { material_value = new_material_value; }

    unsigned short int get_piece_type() { return piece_type; }
    void set_piece_type(short int new_piece_type) { piece_type = new_piece_type; }

    bool get_colour() { return colour; }
    void set_colour_value(short int new_colour) { colour = new_colour; }
};




// Forward declarations (https://www.learncpp.com/cpp-tutorial/forward-declarations/).
tile_ID move(tile_ID starting_pos, tile_ID final_pos);
Piece* board[8][8] = {};




bool check_if_valid_pos(Piece* my_piece, tile_ID starting_pos, tile_ID final_pos){

    bool result = true;

    if (my_piece->get_piece_type() == KNIGHT){

        unsigned short int i = starting_pos[0];
        unsigned short int j = starting_pos[1];

        // Magic number: 8
        tile_ID possible_destinations[8] = {  {i+1, j+2},
                                              {i+1, j+1},
                                              {i+1, j-1},
                                              {i+1, j-2},

                                              {i-1, j+2},
                                              {i-1, j+1},
                                              {i-1, j-1},
                                              {i-1, j-2}  };


        // Magic number: 8
        for (int current_tile = 0; current_tile < 8; current_tile++) {

            if (final_pos == possible_destinations[i]) {

                // Piece destination_piece = (board[possible_destinations[current_tile][0]][possible_destinations[current_tile][1]], starting_pos, my_piece);
                Piece* destination_piece = board[possible_destinations[current_tile][0]][possible_destinations[current_tile][1]];
                if ((destination_piece->get_piece_type() != EMPTY) && (destination_piece->get_colour() == my_piece->get_colour())) {
                    result = false;
                }
            }
        }
    }

    // other pieces here...
    return result;
}





// OOP is pretty and all, but you cannot have this function as a method of the Piece class without symbol redefinitions (i.e a circular, recursive dependency that "will never work nor compile").
tile_ID move(Piece* my_piece, tile_ID starting_pos, tile_ID final_pos) {

    tile_ID new_pos = starting_pos;

    if ((my_piece->get_piece_type()) != EMPTY){
        if (check_if_valid_pos(my_piece, starting_pos, final_pos)){
            new_pos = final_pos;
        }
    }
    
    return new_pos;
}



int main() { return 0; }
