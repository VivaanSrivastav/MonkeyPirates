#include <bits/stdc++.h>
using namespace std;

/*
In hindsight, it would've been better to save the ascii art as 2D vectors, would allow me to put more than 1 art on a line among other things.
I noticed this a little late however.
*/
void IntroText(){
   cout << " |  \\/  |           | |             " << endl;
   cout << " | \\  / | ___  _ __ | | _____ _   _ " << endl;
   cout << " | |\\/| |/ _ \\| '_ \\| |/ / _ \\ | | |" << endl;
   cout << " | |  | | (_) | | | |   <  __/ |_| |" << endl;
   cout << " |_|__|_|\\___/|_| |_|_|\\_\\___|\\__, |" << endl;
   cout << " |  __ (_)         | |         __/ |" << endl;
   cout << " | |__) | _ __ __ _| |_ ___  _|___/ " << endl;
   cout << " |  ___/ | '__/ _` | __/ _ \\/ __|   " << endl;
   cout << " | |   | | | | (_| | ||  __/\\__ \\   " << endl;
   cout << " |_|   |_|_|  \\__,_|\\__\\___||___/   " << endl;
}

void IntroAscii(){
   cout << "            __,__" << endl;
   cout << "   .--.  .-\"     \"-.  .--." << endl;
   cout << "  / .. \\/  .-. .-.  \\/ .. \\" << endl;
   cout << " | |  '|  /   Y   \\  |'  | |" << endl;
   cout << " | \\   \\  \\ 0 | 0 /  /   / |" << endl;
   cout << "  \\ '- ,\\.-\"`` ``\"-./, -' /" << endl;
   cout << "   `'-' /_   ^ ^   _\\ '-'`" << endl;
   cout << "       |  \\._   _./  |" << endl;
   cout << "       \\   \\ `~` /   /" << endl;
   cout << "        '._ '-=-' _.'" << endl;
   cout << "           '~---~'" << endl;
}

void Brack(){
   cout << "           .\"`\"." << endl;
   cout << "       .-./ _=_ \\.-." << endl;
   cout << "      {  (,(oYo),) }}" << endl;
   cout << "      {{ |   \"   |} }" << endl;
   cout << "      { { \\(---)/  }}" << endl;
   cout << "      {{  }'-=-'{ } }" << endl;
   cout << "      { { }._:_.{  }}" << endl;
   cout << "      {{  } -:- { } }" << endl;
   cout << "      {_{ }`===`{  _}" << endl;
   cout << "     ((((\\)     (/))))" << endl;
}

void AngryHarith(){
   cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣶⣶⣶⣤⣀⣀⣀⣠⡴⣿⣦⣤⣤⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣶⣿⠟⠉⠀⠀⠀⠀⠈⠙⠻⣯⡁⠀⠀⠀⠀⠀⠀⠉⠙⣟⣶⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⠋⠀⠀⠀⠀⠐⢶⣤⡀⠀⠈⠙⢶⣄⡀⠀⠀⠀⠀⠀⠈⠙⠛⠷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   cout << "⠀⠀⢀⣠⣴⣶⣶⣤⣴⣿⣿⣿⣿⣿⡏⠀⠀⢀⣴⠾⠛⠋⠉⠛⢶⣄⠀⠀⠈⠛⠷⣦⣄⣀⠀⠀⠀⠀⠀⠈⠻⣄⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   cout << "⠀⣰⡿⠛⠉⠁⠀⠈⠙⢿⣿⣿⣿⣿⡇⠀⠀⣸⣿⣦⠀⠀⠀⠀⠀⠉⠻⢦⣀⡀⠀⠈⠙⠛⠿⢶⣶⣤⣤⣤⣤⣾⣷⣶⣤⣀⠀⠀⠀⠀" << endl;
   cout << "⢠⡿⠀⠰⠟⣻⣧⠀⠀⠸⣿⣿⣿⣿⠃⠀⠀⣿⠛⠿⢷⣤⣄⡀⠀⠀⠀⠀⢹⡟⠁⠀⠀⠀⣤⣄⣀⡀⣀⣠⣤⣶⣶⣶⠈⢻⣆⠀⠀⠀" << endl;
   cout << "⣼⡇⠀⠀⣼⠟⣿⠀⠀⠀⣿⣿⣿⣿⠀⠀⣀⣹⣧⣀⣀⠈⠙⠻⠷⣦⣤⣀⣼⠇⠀⠀⠀⢀⣼⡟⠛⠛⠛⠋⠉⠀⠹⣷⡀⣸⡟⠀⠀⠀" << endl;
   cout << "⢿⡇⠀⠀⠉⠀⢻⣇⣠⣴⠿⠟⠛⠉⠀⠈⠉⠀⠀⠉⠉⠙⠛⠶⣤⣤⡿⢟⡁⠀⠀⠀⠀⣾⣿⣿⡀⠀⠀⠀⠀⠀⠀⢻⣿⠟⠁⠀⠀⠀" << endl;
   cout << "⢸⣇⠀⠀⢀⣤⡾⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⣼⠛⢛⡷⠶⠾⠟⢿⣏⠙⠻⠷⢦⣤⣀⣀⠀⣸⣿⣷⣶⣤⡀⠀" << endl;
   cout << "⠈⢿⣦⣴⡟⠉⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣤⣤⣤⣀⣀⡀⠀⠀⠀⠀⠙⠇⠙⠻⣦⡀⠀⠈⡻⠿⣶⣤⣄⣈⠉⠛⣿⡿⠃⠀⠀⠙⢿⣄" << endl;
   cout << "⠀⠀⢸⡟⢀⠀⠀⠀⠀⣠⡶⠟⠋⠁⢹⡿⣧⠀⠀⠀⠉⠙⠻⢶⣄⡀⠀⠀⠀⠀⠙⣷⡶⠟⠛⠻⢦⣿⠟⠛⠻⢿⣿⣡⡴⠿⡿⠂⠈⣿" << endl;
   cout << "⠀⠀⣿⡿⠋⠀⢀⣴⣿⠉⠀⠀⠀⠀⢸⡇⠹⣧⠀⠀⠀⠀⠀⠀⠈⠻⣦⡀⠀⠀⠀⠿⠁⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠙⢷⣄⠀⠀⠀⢸" << endl;
   cout << "⢀⣾⠏⠀⢀⣴⣿⠏⣿⠀⠀⠀⠀⠀⣾⠁⠀⢻⣆⠀⠀⠀⠀⠀⠀⣰⣿⡟⠶⣤⣤⣤⣤⣴⠶⠶⠶⠶⣤⣄⡀⠀⠀⠀⠀⢻⣆⠀⠀⣼" << endl;
   cout << "⣸⡏⠀⢠⡟⢸⡟⠀⢿⡄⠀⠀⠀⢰⡏⠀⠀⠀⣿⡄⠀⠀⠀⠀⢠⡟⠁⣿⠀⠀⠀⠀⣸⣿⡆⠀⠀⠀⠀⢹⣿⣦⠀⠀⠀⠀⢿⣤⣼⠟" << endl;
   cout << "⣿⡇⠀⣿⠀⣼⡇⠀⠸⣧⠀⠀⠀⣾⠃⠀⠀⠀⠸⣧⠀⠀⠀⣰⡟⠀⠀⢹⡆⠀⠀⢰⡟⠹⡇⠀⠀⠀⢀⣿⣿⠈⢧⡀⠀⠀⣸⡟⠁⠀" << endl;
   cout << "⣿⡇⠀⢻⣄⣿⡇⠀⠀⢻⣆⠀⣼⡏⠀⠀⠀⠀⠀⢿⡀⢠⣾⠏⠀⠀⠀⢸⡇⠀⣰⡟⠀⠀⣷⠀⠀⢀⣾⠃⢸⡆⠈⣷⠀⢸⣿⡇⠀⠀" << endl;
   cout << "⢹⣧⠀⠀⠛⠿⣧⣀⡀⠀⣻⣾⣟⡀⠀⠀⠀⠀⢀⣸⣷⡟⠁⠀⠀⠀⠀⢈⣷⣴⠟⠀⠀⠀⣿⠀⢠⡾⠃⠀⢸⡇⠀⠸⣇⠀⣿⡇⠀⠀" << endl;
   cout << "⠈⠻⣷⣄⣀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠛⠛⠾⠿⣧⣤⣀⠀⠀⣿⣴⠟⠀⠀⠀⢸⡇⠀⢀⣿⠀⠸⡇⠀⠀" << endl;
   cout << "⠀⠀⠈⠙⠻⠿⣿⣿⡿⠟⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠻⠿⣧⣀⠀⠀⠀⢸⣇⣴⡿⣿⠀⠀⣿⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⠀⠀⠘⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⢦⣤⣿⡿⠋⢠⡿⠀⢸⡏⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠷⣦⣄⠈⠛⠷⠶⠛⠁⣠⣿⠃⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⣷⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣽⣿⣶⣶⣶⣶⡾⠟⠁⠀⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠛⠿⠶⣶⣦⣤⣤⣤⣄⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠙⠛⠛⠿⠿⣷⣶⣶⣶⠾⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
}

void Door(){
   cout << "      ______" << endl;
   cout << "   ,-' ;  ! `-." << endl;
   cout << "  / :  !  :  . \\" << endl;
   cout << " |_ ;   __:  ;  |" << endl;
   cout << " )| .  :)(.  !  |" << endl;
   cout << " |\"    (##)  _  |" << endl;
   cout << " |  :  ;`'  (_) (" << endl;
   cout << " |  :  :  .     |" << endl;
   cout << " )_ !  ,  ;  ;  |" << endl;
   cout << " || .  .  :  :  |" << endl;
   cout << " |\" .  |  :  .  |" << endl;
   cout << " |mt-2_;----.___|" << endl;
}

void BrackFace(){
   cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⠀⠀⠀⣤⠤⠽⢏⢩⣕⡚⠯⣝⡒⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⠀⢀⣠⠼⣎⣿⣿⣷⣿⣿⣷⣿⣿⣷⣌⡓⢄⠀⠀⠀⠀⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⡔⣩⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣎⢣⠀⠀⠀⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⢰⢡⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⡇⠀⠀⠀⠀" << endl;
   cout << "⠀⠀⠀⢀⠞⣨⣭⣭⣭⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣭⣭⣍⡻⡄⠀⠀⠀" << endl;
   cout << "⠀⠀⠀⡼⢸⣿⡿⠿⢿⠿⠻⠿⢿⣿⣿⣿⢿⠟⠻⡿⠿⢿⣿⣧⢱⠀⠀⠀" << endl;
   cout << "⢀⡖⠒⢧⢸⡏⠀⠠⣀⡀⠀⠠⡐⡈⠁⠄⠀⠀⡀⣄⡄⠀⠹⡿⢸⠐⠢⡀" << endl;
   cout << "⠸⡈⡩⢾⡘⣷⡄⠘⢿⣿⣦⣤⣼⣿⣿⣯⣠⣴⣿⣽⠇⢀⣼⡇⡧⠮⠁⡇" << endl;
   cout << "⠀⢳⡠⢊⣼⡏⠈⠀⠀⠀⣀⠪⣝⠛⠛⣻⠵⣄⠀⠀⠂⠀⢹⣧⣑⢤⡼⠁" << endl;
   cout << "⠀⡸⣡⣾⡿⣿⣶⣦⣄⡀⠈⠒⠉⠣⠜⠉⠙⠉⢰⣠⣴⣿⡿⡟⢿⣮⢫⡀" << endl;
   cout << "⣼⢕⣿⡏⠀⠈⢞⣿⡿⠂⠀⠀⠀⠐⠣⠀⠀⠀⠈⢿⣿⡍⠈⠀⢸⣿⡇⣷" << endl;
   cout << "⠸⣸⣿⣏⣆⠀⣾⡿⢰⣇⣨⣀⣦⠤⠧⠜⠓⠂⠤⣙⢿⣿⢀⢠⣿⣿⡇⡇" << endl;
   cout << "⠀⢣⣿⣿⣿⣼⣿⡇⠐⠋⡉⠀⢤⣴⡶⠶⠖⠀⠀⠤⣽⣿⣿⣿⣿⣿⣿⠁" << endl;
   cout << "⠀⠀⠙⠙⢿⣿⣿⣿⣶⣮⠀⠀⠀⣠⣄⠀⠀⠀⣠⣼⣿⣿⣿⡿⠋⠝⠁⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⠙⠏⠻⣿⣿⣿⣶⣾⣿⣿⣿⣿⣿⣿⣿⠟⠹⠋⠀⠀⠀⠀⠀" << endl;
   cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠉⠛⠿⠛⠛⠻⠛⠉⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
}

void SittingMonkey(){
   cout << "       .=\"=." << endl;
   cout << "     _/.-.-.\\_     _" << endl;
   cout << "    ( ( o o ) )    ))" << endl;
   cout << "     |/  \"  \\|    //" << endl;
   cout << "      \\'---'/    //" << endl;
   cout << "      /`\"\"\"`\\\\  ((" << endl;
   cout << "     / /_,_\\ \\\\  \\\\" << endl;
   cout << "     \\_\\\\_'__/ \\  ))" << endl;
   cout << "     /`  /`~\\  |//" << endl;
   cout << "    /   /    \\  /" << endl;
   cout << ",--`,--'\\/\\    /" << endl;
   cout << " '-- \"--'  '--'" << endl;
}

void BrackHead(){
   cout << "           .\"`\"." << endl;
   cout << "       .-./ _=_ \\.-." << endl;
   cout << "      {  (,(oYo),) }}" << endl;
   cout << "      {{ |   \"   |} }" << endl;
   cout << "      { { \\(---)/  }}" << endl;
}

void BattleTime(){
   Blank(2);
   cout << " ________  ________  _________  _________  ___       _______      " << endl;
   cout << "|\\   __  \\|\\   __  \\|\\___   ___\\\\___   ___\\\\  \\     |\\  ___ \\     " << endl;
   cout << "\\ \\  \\|\\ /\\ \\  \\|\\  \\|___ \\  \\_\\|___ \\  \\_\\ \\  \\    \\ \\   __/|    " << endl;
   cout << " \\ \\   __  \\ \\   __  \\   \\ \\  \\     \\ \\  \\ \\ \\  \\    \\ \\  \\_|/__  " << endl;
   cout << "  \\ \\  \\|\\  \\ \\  \\ \\  \\   \\ \\  \\     \\ \\  \\ \\ \\  \\____\\ \\  \\_|\\ \\ " << endl;
   cout << "   \\ \\_______\\ \\__\\ \\__\\   \\ \\__\\     \\ \\__\\ \\ \\_______\\ \\_______\\" << endl;
   cout << "    \\|_______|\\|__|\\|__|    \\|__|      \\|__|  \\|_______|\\|_______|" << endl;
   cout << "                                                                  " << endl;
   Wait(1000);
   cout << " _________  ___  _____ ______   _______                           " << endl;
   cout << "|\\___   ___\\\\  \\|\\   _ \\  _   \\|\\  ___ \\                          " << endl;
   cout << "\\|___ \\  \\_\\ \\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|                         " << endl;
   cout << "     \\ \\  \\ \\ \\  \\ \\  \\\\|__| \\  \\ \\  \\_|/__                       " << endl;
   cout << "      \\ \\  \\ \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\                      " << endl;
   cout << "       \\ \\__\\ \\ \\__\\ \\__\\    \\ \\__\\ \\_______\\                     " << endl;
   cout << "        \\|__|  \\|__|\\|__|     \\|__|\\|_______|                     " << endl;
   cout << "                                                                  " << endl;
   Wait(1000);
}

void BattleWon(){
   cout << "  ________  _________  _________  ___       _______      " << endl;
   cout << "|\\   __  \\|\\   __  \\|\\___   ___\\\\___   ___\\\\  \\     |\\  ___ \\     " << endl;
   cout << "\\ \\  \\|\\ /\\ \\  \\|\\  \\|___ \\  \\_\\|___ \\  \\_\\ \\  \\    \\ \\   __/|    " << endl;
   cout << " \\ \\   __  \\ \\   __  \\   \\ \\  \\     \\ \\  \\ \\ \\  \\    \\ \\  \\_|/__  " << endl;
   cout << "  \\ \\  \\|\\  \\ \\  \\ \\  \\   \\ \\  \\     \\ \\  \\ \\ \\  \\____\\ \\  \\_|\\ \\ " << endl;
   cout << "   \\ \\_______\\ \\__\\ \\__\\   \\ \\__\\     \\ \\__\\ \\ \\_______\\ \\_______\\" << endl;
   cout << "    \\|_______|\\|__|\\|__|    \\|__|      \\|__|  \\|_______|\\|_______|" << endl;
   cout << "                                                                  " << endl;
   Wait(1000);
   cout << " ___       __   ________  ________                                " << endl;
   cout << "|\\  \\     |\\  \\|\\   __  \\|\\   ___  \\                              " << endl;
   cout << "\\ \\  \\    \\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\                             " << endl;
   cout << " \\ \\  \\  __\\ \\  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\                            " << endl;
   cout << "  \\ \\  \\|\\__\\_\\  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\                           " << endl;
   cout << "   \\ \\____________\\ \\_______\\ \\__\\\\ \\__\\                          " << endl;
   cout << "    \\|____________|\\|_______|\\|__| \\|__|                          " << endl;
   cout << "                                                                  " << endl;
   Wait(1000);
}

void BattleLost(){
   cout << "  ________  _________  _________  ___       _______      " << endl;
   cout << "|\\   __  \\|\\   __  \\|\\___   ___\\\\___   ___\\\\  \\     |\\  ___ \\     " << endl;
   cout << "\\ \\  \\|\\ /\\ \\  \\|\\  \\|___ \\  \\_\\|___ \\  \\_\\ \\  \\    \\ \\   __/|    " << endl;
   cout << " \\ \\   __  \\ \\   __  \\   \\ \\  \\     \\ \\  \\ \\ \\  \\    \\ \\  \\_|/__  " << endl;
   cout << "  \\ \\  \\|\\  \\ \\  \\ \\  \\   \\ \\  \\     \\ \\  \\ \\ \\  \\____\\ \\  \\_|\\ \\ " << endl;
   cout << "   \\ \\_______\\ \\__\\ \\__\\   \\ \\__\\     \\ \\__\\ \\ \\_______\\ \\_______\\" << endl;
   cout << "    \\|_______|\\|__|\\|__|    \\|__|      \\|__|  \\|_______|\\|_______|" << endl;
   cout << "                                                                  " << endl;
   Wait(1000);
   cout << " ___       ________  ________  _________                          " << endl;
   cout << "|\\  \\     |\\   __  \\|\\   ____\\|\\___   ___\\                        " << endl;
   cout << "\\ \\  \\    \\ \\  \\|\\  \\ \\  \\___|\\|___ \\  \\_|                        " << endl;
   cout << " \\ \\  \\    \\ \\  \\\\\\  \\ \\_____  \\   \\ \\  \\                         " << endl;
   cout << "  \\ \\  \\____\\ \\  \\\\\\  \\|____|\\  \\   \\ \\  \\                        " << endl;
   cout << "   \\ \\_______\\ \\_______\\____\\_\\  \\   \\ \\__\\                       " << endl;
   cout << "    \\|_______|\\|_______|\\_________\\   \\|__|                       " << endl;
   cout << "                       \\|_________|                               " << endl;
   cout << "                                                                  " << endl;
   Wait(1000);
}

void Ricky(){
   cout << "" << endl;
   cout << "                 / _,\\" << endl;
   cout << "                 \\_\\" << endl;
   cout << "      ,,,,    _,_)  #      /)" << endl;
   cout << "     (= =)D__/    __/     //" << endl;
   cout << "    C/^__)/     _(    ___//" << endl;
   cout << "      \\_,/  -.   '-._/,--'" << endl;
   cout << "_\\\\_,  /           -//." << endl;
   cout << " \\_ \\_/  -,._ _     ) )" << endl;
   cout << "   \\/    /    )    / /" << endl;
   cout << "   \\-__,/    (    ( (" << endl;
   cout << "              \\.__,-)\\_" << endl;
   cout << "               )\\_ / -(" << endl;
   cout << "              / -(////" << endl;
   cout << "             ////" << endl;
}

void Marty(){
   cout << "    EEEK!" << endl;
   cout << "      /  \\   ~~|~~" << endl;
   cout << "     (|00|)    |" << endl;
   cout << "      (==)  --/" << endl;
   cout << "    ___||___" << endl;
   cout << "   / _ .. _ \\" << endl;
   cout << "  //  |  |  \\\\" << endl;
   cout << " //   |  |   \\\\" << endl;
   cout << " ||  / /\\ \\  ||" << endl;
   cout << "_|| _| || |_ ||_  " << endl;
   cout << "\\|||___||___|||/" << endl;
}

void Barto(){
   cout << "" << endl;
   cout << "      |>(|)<|" << endl;
   cout << "      .-'^'-." << endl;
   cout << "     '/\"'\"^\"\\'" << endl;
   cout << "    :( *   * ):" << endl;
   cout << "    ::)  ,| (::" << endl;
   cout << "    '(       )'          _." << endl;
   cout << "     '\\ --- /'          / /" << endl;
   cout << "   .-'       '-.      .__D" << endl;
   cout << " ,\"      |      \\    / : (=|" << endl;
   cout << ":   Y    |    \\  \\  /  : (=|" << endl;
   cout << "|   |o__/ \\__o:   \\/  \" \\ \\" << endl;
   cout << "|   |          \\     '   \"-." << endl;
   cout << "|    `.    ___ \\:._.'" << endl;
   cout << " \".__  \"-\" __ \\ \\" << endl;
   cout << "  .|''---''------|               _" << endl;
   cout << "  / -.          _\"\"-.--.        C )" << endl;
   cout << " '    '/.___.--'        '._    : |" << endl;
   cout << "|     --_   ^\"--...__      ''-.' |" << endl;
   cout << "|        ''---.o)    \"\"._        |" << endl;
   cout << " ^'--.._      |o)        '`-..._.jku" << endl;
   cout << "        '--.._|o)" << endl;
   cout << "              'O)" << endl;
}
