void input()
{
    prevDir = dir;

    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameOver = true;
        default:
            break;
        }
    }
}

void logic()
{
    prev_x = snake_x;
    prev_y = snake_y;

    switch (dir)
    {
    case 1:
        snake_x -= 1;
        if (snake_x == -1)
        {
            snake_x = x + 1;
        }

        if (prevDir == 2)
        {
            snake_y += 1;
        }
        break;
    case 2:
        snake_x += 1;
        if (snake_x == x + 2)
        {
            snake_x = -1;
        }

        if (prevDir == 1)
        {
            snake_y -= 1;
        }
        break;
    case 3:
        snake_y -= 1;
        if (snake_y == -1)
        {
            snake_y = y + 1;
        }

        if (prevDir == 4)
        {
            snake_x += 1;
        }
        break;
    case 4:
        snake_y += 1;
        if (snake_y == y + 1)
        {
            snake_y = -1;
        }

        if (prevDir == 3)
        {
            snake_x -= 1;
        }
        break;
    default:
        break;
    }

    if (score == 100)
    {
        gameOver = true;
    }

    if (snake_x == coords[0] && snake_y == coords[1])
    {
        score += 1;
        spawnFruit();
    }

    if (score > prev_score)
    {
        tail[score - 1] = 1;
        prev_score += 1;
    }

    int prev_tail[2] = { prev_x, prev_y };
    int prev_prev_tail[2];

    for (int i = 0; i < score; i++)
    {

        if (snake_x == tailPosition[i][0] && snake_y == tailPosition[i][1])
        {
            gameOver = true;
        }

        if (i == 0)
        {
            prev_tail[0] = tailPosition[0][0];
            prev_tail[1] = tailPosition[0][1];
            tailPosition[0][0] = prev_x;
            tailPosition[0][1] = prev_y;
        }
        else
        {
            prev_prev_tail[0] = tailPosition[i][0];
            prev_prev_tail[1] = tailPosition[i][1];
            tailPosition[i][0] = prev_tail[0];
            tailPosition[i][1] = prev_tail[1];
            prev_tail[0] = prev_prev_tail[0];
            prev_tail[1] = prev_prev_tail[1];
        }
    }
}