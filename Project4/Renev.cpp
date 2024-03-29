void init_board(int x, int y)
{
    int grass;

    for (int i = 0; i < x + 2; i++)
    {
        grass = rand() % 100;

        if ((i == x + 1) || (i % (x + 2) == 0))
        {
            board_header.append(" ");
            board_body.append(i % 5 == 0 ? "^" : " ");

            if (i == x + 1)
            {
                board_header.append("\n");
                board_body.append("\n");
            }
        }
        else
        {
            board_header.append(i % 3 == 0 ? "`" : " ");
            board_body.append(grass > 70 ? (i % 2 == 0 ? "^" : "`") : " ");
        }
    }

    for (int i = 0; i < y + 2; i++)
    {
        if ((i == 0) || (i == y + 1))
        {
            board.append(board_header);
        }
        else
        {
            if (i % 2 == 0)
            {
                board.append(board_body);
            }
            else
            {
                board.append(" ");
                board.append(board_body);
                board.erase((i * (x + 3)) + x + 2, 1);
            }
        }
    }
}

void renderFruit()
{
    gotoxy(coords[0], coords[1]);
    std::cout << "\033[41m"
        << "\033[93m"
        << "*"
        << "\033[0m"
        << "\033[0m";
}

void render()
{
    gotoxy(0, 0);
    std::cout << "\033[47m"
        << "\033[32m" << board << "\033[0m"
        << "\033[0m";
    renderFruit();
    gotoxy(snake_x, snake_y);

    if (dir > 2)
    {
        gotoxy(snake_x, snake_y);
        std::cout << "\033[42m"
            << "\033[91m"
            << ":"
            << "\033[0m"
            << "\033[0m";
    }
    else
    {
        gotoxy(snake_x, snake_y);
        std::cout << "\033[42m"
            << "\033[91m"
            << ":"
            << "\033[0m"
            << "\033[0m";
    }

    for (int i = 0; i < score; i++)
    {
        gotoxy(tailPosition[i][0], tailPosition[i][1]);

        if ((i > 0) && (i == score - 1))
        {
            std::cout << "\033[42m"
                << "\033[31m" << (dir == 1 ? ">" : "") << (dir == 2 ? "<" : "") << (dir == 3 ? "V" : "") << (dir == 4 ? "A" : "") << "\033[0m"
                << "\033[0m";
        }
        else
        {
            std::cout << "\033[42m"
                << "\033[33m" << (dir < 3 ? "-" : "|") << "\033[0m"
                << "\033[0m";
        }
    }

    gotoxy(x / 2 - 7, y + 3);
    std::cout << "       .-----.\n";
    gotoxy(x / 2 - 7, y + 4);
    std::cout << "Score: | "
        << "\033[32m" << (score < 10 ? "00" : "") << ((score >= 10) && (score < 100) ? "0" : "") << score << "\033[0m"
        << " |\n";
    gotoxy(x / 2 - 7, y + 5);
    std::cout << "       '-----'\n";
}
