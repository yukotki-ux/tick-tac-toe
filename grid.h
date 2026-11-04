class grid {
    private:
        char board[3][3]
    public:
        createGrid();
        void showBoard();
        bool isEmpty();
        bool isFilled();
        bool checkWin();
    
}