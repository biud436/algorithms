#include <iostream>

struct _stone {
    int x;
    int y;
} stone;

struct _king {
    int x;
    int y;
} king;

typedef struct _MoveCommand {
    std::string command;
    int x;
    int y;
} MoveCommand;

const MoveCommand moveCommands[8] = {
    {"R", 1, 0},
    {"L", -1, 0},
    {"B", 0, -1},
    {"T", 0, 1},
    {"RT", 1, 1},
    {"LT", -1, 1},
    {"RB", 1, -1},
    {"LB", -1, -1}
};
const MoveCommand EMPTY_MOVE_COMMAND = {"", 0, 0};

const int BOARD_SIZE = 8;
const char COLUMN_START = 'A';
const char COLUMN_END = 'H';
const int ROW_START = 1;
const int ROW_END = 8;

bool isOutOfBoard(int x, int y) {
    return (x < COLUMN_START || x > COLUMN_END || y < ROW_START|| y > ROW_END);
}

MoveCommand getMoveCommand(std::string command) {
    for (int i = 0; i < 8; i++) {
        if (moveCommands[i].command == command) {
            return moveCommands[i];
        }
    }

    return EMPTY_MOVE_COMMAND;
}

int main() {
    std::string kingPosition, stonePosition;
    int N;

    std::cin >> kingPosition >> stonePosition >> N;

    std::string *commands = new std::string[N];

    for (int i = 0; i < N; i++) {
        std::cin >> commands[i];
    }

    king.x = kingPosition[0];
    king.y = kingPosition[1] - '0';

    stone.x = stonePosition[0];
    stone.y = stonePosition[1] - '0';

    int nextKingX, nextKingY, nextStoneX, nextStoneY;

    for (int i = 0; i < N; ++i) {
        MoveCommand moveCommand = getMoveCommand(commands[i]);

        nextKingX = king.x + moveCommand.x;
        nextKingY = king.y + moveCommand.y;

        if (isOutOfBoard(nextKingX, nextKingY)) {
            continue;
        }

        if (nextKingX == stone.x && nextKingY == stone.y) {
            nextStoneX = stone.x + moveCommand.x;
            nextStoneY = stone.y + moveCommand.y;
            if (isOutOfBoard(nextStoneX, nextStoneY)) {
                continue;
            }
            stone.x = nextStoneX;
            stone.y = nextStoneY;
        }

        king.x = nextKingX;
        king.y = nextKingY;
    }

    std::cout << static_cast<char>(king.x) << king.y << std::endl;
    std::cout << static_cast<char>(stone.x) << stone.y << std::endl;

    delete[] commands;

    return 0;
}
