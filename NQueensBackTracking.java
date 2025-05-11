import java.util.Scanner;

public class NQueensBackTracking {

    // Function to print the board
    private static void printBoard(int[][] board) {
        for (int[] row : board) {
            for (int column : row) {
                System.out.print(column == 1 ? " Q " : " . ");
            }
            System.out.println();
        }
        System.out.println();
    }

    // Function to check if the queen can be placed at board[row][col]
    private static boolean isSafe(int[][] board, int row, int col) {
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }
        for (int i = row, j = col; i < board.length && j >= 0; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }
        return true;
    }

    // Recursive function to solve the N-Queens problem
    private static boolean solveNQueens(int[][] board, int col) {
        if (col >= board.length) {
            return true;
        }
        for (int i = 0; i < board.length; i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 1;
                if (solveNQueens(board, col + 1)) {
                    return true;
                }
                board[i][col] = 0; // Backtrack
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of queens: ");
        int N = scanner.nextInt();
        int[][] board = new int[N][N];

        if (!solveNQueens(board, 0)) {
            System.out.println("Solution does not exist");
        } else {
            printBoard(board);
        }
        scanner.close();
    }
}
