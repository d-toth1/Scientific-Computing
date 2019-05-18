#include <iostream>
#include <vector>
#include <random>
#include <functional>

using namespace std;

int row_win(const vector<vector<int>> &board);
int col_win(const vector<vector<int>> &board);
int diag_win(const vector<vector<int>> &board);

int main(int argc, char* argv[]){

    if(argc < 3){
        cout << "Enter arguments for board size and trials." << endl;
        return 0;
    }

    int n = stoi(argv[1]);
    long long trials = stoll(argv[2]);

    int seed_value;
    random_device rd;
    seed_value = rd();
    mt19937 generator(seed_value);
    uniform_int_distribution<int> distribution(0, n-1);
    auto draw_row = bind(distribution, ref(generator));
    auto draw_col = bind(distribution, ref(generator));

    int x, y;
    int player_1_wins = 0;
    int player_2_wins = 0;
    int draws = 0;

    int player_1 = 1;
    int player_2 = -1;

    for(long long i = 0; i < trials; i++){

        bool win = false;
        bool draw = false;
        bool is_player_1 = true;
        vector<vector<int>> board(n, vector<int>(n));
        int size = board.size();

        int turns = 0;

        while(true){

            if(is_player_1 == true){
                while(is_player_1 == true){
                    x = draw_row();
                    y = draw_col();
                    if(board[x][y] == 0){
                        board[x][y] = player_1;
                        is_player_1 = false;
                        turns++;
                    }
                }
            }


            if(row_win(board) == 1){
                player_1_wins++;
                break;
            } else if(row_win(board) == -1){
                player_2_wins++;
                break;
            }
            if(col_win(board) == 1){
                player_1_wins++;
                break;
            } else if(col_win(board) == -1){
                player_2_wins++;
                break;
            }
            if(diag_win(board) == 1){
                player_1_wins++;
                break;
            } else if(diag_win(board) == -1){
                player_2_wins++;
                break;
            }


            if(turns == size*size && win == false){
                draw = true;
                draws++;
                break;
            }


            if(is_player_1 == false){
                while(is_player_1 == false){
                    x = draw_row();
                    y = draw_col();
                    if(board[x][y] == 0){
                        board[x][y] = player_2;
                        is_player_1 = true;
                        turns++;
                    }
                }
            }


            if(row_win(board) == 1){
                player_1_wins++;
                break;
            } else if(row_win(board) == -1){
                player_2_wins++;
                break;
            }
            if(col_win(board) == 1){
                player_1_wins++;
                break;
            } else if(col_win(board) == -1){
                player_2_wins++;
                break;
            }
            if(diag_win(board) == 1){
                player_1_wins++;
                break;
            } else if(diag_win(board) == -1){
                player_2_wins++;
                break;
            }


            if(turns == size*size && win == false){
                draws++;
                break;
            }
        }
    }
    cout << "Player 1: " << double(player_1_wins)/double(trials) << endl;
    cout << "Player 2: " << double(player_2_wins)/double(trials) << endl;
    cout << "Draws: " << double(draws)/double(trials) << endl;

    return 0;
}

int col_win(const vector<vector<int>> &board){
    for(int j = 0; j < board.size(); j++){
        int total = 0;
        for(int i = 0; i < board.size(); i++){
            total += board[i][j];
        }
        if(total == board.size()){
            return 1;
        } else if(total == 0 - board.size()){
            return -1;
        }
    }
    return 0;
}

int row_win(const vector<vector<int>> &board){
    for(int i = 0; i < board.size(); i++){
        int total = 0;
        for(int j = 0; j < board.size(); j++){
            total += board[i][j];
        }
        if(total == board.size()){
            return 1;
        } else if(total == 0 - board.size()){
            return -1;
        }

    }
    return 0;
}

int diag_win(const vector<vector<int>> &board){
    int total1 = 0;
    int total2 = 0;
    int j;
    for(int i = 0; i < board.size(); i++){
        j = board.size() - i - 1;
        total1 += board[i][i];
        total2 += board[i][j];
    }
    if( (total1 == board.size()) || (total2 == board.size())){
        return 1;
    } else if(total1 == 0 - board.size() || (total2 == 0 - board.size())){
        return -1;
    }
    return 0;
}
