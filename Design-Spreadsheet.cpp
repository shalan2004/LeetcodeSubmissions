class Spreadsheet {
public:
    vector<vector<int>> grid ;
    Spreadsheet(int rows) {
        grid.resize(rows+1 , vector<int>(26 , 0)) ;
    }

    
    void setCell(string cell, int value) {
        pair<int,int> p = tell(cell) ;
        int row = p.first ;
        int col = p.second ;
        grid[row][col] = value ;
    }
    
    void resetCell(string cell) {
        pair<int,int> p = tell(cell) ;
        int row = p.first ;
        int col = p.second ;
        grid[row][col] = 0 ;
    }

    pair<int,int> tell(string cell) {
        int col = cell[0] - 'A' ;
        int row ;
        string str ;
        for(int i = 1 ;i < cell.size() ; i++) {
            str.push_back(cell[i]) ;
        }
        //cout << str.size() << endl ;
        if(str.size() == 1 ) row = str[0] - '0' -1 ;
        else row = stoi(str)-1 ;
        //cout << row << " " << col << " " << cell << endl ;
        return {row , col} ;
    }
    
    int getValue(string f) {
        int row1 = 0 , col1 = 0 ;
        int row2 , col2;

        int val1 , val2 ;
        string x , y ;
        int i = 0 ;
        while( i<f.size() && f[i] != '+' ) {
            i++ ;
        }
        x = f.substr(1 , i-1) ;
        y = f.substr(i+1) ;
        //cout << x << " " << y << endl ;
        
        if(isalpha(x[0] )) {
            pair<int,int> p = tell(x) ;
            row1 = p.first  ;
            col1 = p.second ;
            val1 = grid[row1][col1] ;
            //cout << x << " " << row1 << " " << col1 << endl ;
        }

        else {
            if( x.size() == 1 ) val1 = x[0] - '0' ;
            else val1 = stoi(x) ;
        }

        //cout << val1 << " " ;

        if( isalpha(y[0])) {
            row2 = tell(y).first ;
            col2 = tell(y).second ;
            val2 = grid[row2][col2] ;
        }

        else {
            if( y.size() == 1 ) val2 = y[0] - '0' ;
            else val2 = stoi(y) ;

            //cout << " y = " <<  val2 << endl ;
        }

        //cout << val2 << " " << endl ;

        //cout << val1 + val2 << " sum "  << endl ;

        return val1 + val2 ;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */