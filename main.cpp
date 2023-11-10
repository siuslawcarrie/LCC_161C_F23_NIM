
/
//

#include <iostream> // for cin and cout

using  namespace  std;

int  main()
{
    // define constants
    const int MAX_STIX = 11;
    const char STICK = '|';
    const int BIG_NUM = 100;
    const char EOL = '\n';

    // display instructions
    cout << "Welcome to Nim!" << endl;
    cout << "Each player will take turns removing 1, 2, or 3 sticks from the " << endl;
    cout << "intitial " << MAX_STIX << ". The player removing the last stick wins!" << endl;

    // define variables
    int num_stix = MAX_STIX;
    int move;
    int player = 1;
    bool playing = true;

    while (playing)
    {
        // display board and get move
        cout << "Player " << player << ", it's your turn!" << endl << endl;
        cout << "The game currently looks like this:" << endl << endl;
        for(int i = 0; i < num_stix; i++)
            cout << STICK;
        cout << endl << endl;
        cout << "How many sticks would you like to remove? (1, 2, or 3) ";
        cin >> move;

        // validate move
        do {
            // if illegal move, delete and start over
            if ( move < 1 or move > 3 or move > num_stix )
            {
                // print appropriate error message
                if ( move > num_stix and move < 4 )
                    cout << "can not take more sticks than remain, try again ";
                else
                    cout << "Invalid move, try again ";
                // clear buffer for new move
                cin.clear();
                cin.ignore(BIG_NUM, EOL);
                // get new move
                cin >> move;
            }
        } while ( move < 1 or move > 3 or move > num_stix );

        // update board
        num_stix -= move;

        // check for win
        if ( num_stix <= 0 )
        {
            cout << "Congratulations Player " << player << ", you win!" << endl;
            playing = false;
        }

        // swap player number
        player = (player == 1)?2:1;
    }

    return  0;
}

