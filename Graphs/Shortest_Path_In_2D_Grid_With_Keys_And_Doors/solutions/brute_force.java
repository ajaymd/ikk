import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the function below.
     */
    static int[][] find_shortest_path(String[] grid) {
    	char [][] board = new char[grid.length][grid[0].length()];
    	for(int i = 0; i < grid.length; i++)
    	{
    		for (int j = 0; j < grid[0].length(); j++)
    		{
    			board[i][j] = grid[i].charAt(j);
                //System.out.println(board[i][j]);
    		}
    	}
        return (pathToString(solve(board)));
    }

    private static final class Coord {
		final int y, x;
		Coord(int y, int x) {
			this.y = y;
			this.x = x;
		}
		@Override public String toString() {
			return String.valueOf(this.y).concat(String.valueOf(this.x));
		}
	}
	private static int[][] pathToString(Iterable<Coord> path) {
        int sz = 0;
		for (Coord coord : path)
            sz++;
        //System.out.println(sz);
        int[][] ans = new int[sz][2];
        int i = 0;
        for (Coord coord : path)
        {
            ans[i][0] = coord.y;
            ans[i][1] = coord.x;
            i++;
        }
		return ans;
	}
	private static List<Coord> solve(char[][] board) {
		List<Coord> shortestPathToGoal = new ArrayList<>();
		for (int y = 0; y < board.length; y++)
			for (int x = 0; x < board[y].length; x++)
            {
                // System.out.println(board[y][x]);
				if (board[y][x] == '@'/*Start*/)
					walk(board, y, x, 0, 
                        initVisited(board), new ArrayDeque<>(), shortestPathToGoal);
            }
		return shortestPathToGoal;
	}
	private static void walk(char[][] board, int y, int x, int keyRing, boolean[][] visited,
	                         Deque<Coord> path, List<Coord> shortestPathToGoal) {
        //System.out.println(y);
		if (y < 0 || y >= board.length || x < 0 || x >= board[y].length || visited[y][x])
			return; // outside board or already visited
		char point = board[y][x];
		if (point == '#'/*Water*/)
			return; // cannot walk on water
		if (point == '+'/*Goal*/) {
			shortestPathToGoal.clear();
			shortestPathToGoal.addAll(path);
			shortestPathToGoal.add(new Coord(y, x));
            //System.out.println("---- ----");
			return; // return to look for alternate shorter path
		}
		if (! shortestPathToGoal.isEmpty() && path.size() + 2 >= shortestPathToGoal.size())
			return; // shorter (or equal) path already found
		if (point >= 'A' && point <= 'Z') { // Door
			if ((keyRing & (1 << (point - 'A'))) == 0)
				return; // missing key
		} else if (point >= 'a' && point <= 'z') { // Key
			if ((keyRing & (1 << (point - 'a'))) == 0) {
				keyRing |= (1 << (point - 'a')); // add key to keyring
				visited = initVisited(board); // may now revisit previous steps
			}
		}
		visited[y][x] = true;
		path.addLast(new Coord(y, x));
		walk(board, y    , x + 1, keyRing, visited, path, shortestPathToGoal); // right
		walk(board, y + 1, x    , keyRing, visited, path, shortestPathToGoal); // down
		walk(board, y    , x - 1, keyRing, visited, path, shortestPathToGoal); // left
		walk(board, y - 1, x    , keyRing, visited, path, shortestPathToGoal); // up
		path.removeLast();
		visited[y][x] = false;
	}
	private static boolean[][] initVisited(char[][] board) {
		boolean[][] visited = new boolean[board.length][];
		for (int y = 0; y < board.length; y++)
			visited[y] = new boolean[board[y].length];
		return visited;
	}

	public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        final String fileName = System.getenv("OUTPUT_PATH");
        BufferedWriter bw = null;
        if (fileName != null) {
            bw = new BufferedWriter(new FileWriter(fileName));
        }
        else {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        int[][] res;
        int grid_size = 0;
        grid_size = Integer.parseInt(in.nextLine().trim());

        String[] grid = new String[grid_size];
        for(int i = 0; i < grid_size; i++) {
            String grid_item;
            try {
                grid_item = in.nextLine();
            } catch (Exception e) {
                grid_item = null;
            }
            grid[i] = grid_item;
        }

        res = find_shortest_path(grid);
        int res_rowLength = res.length;
        int res_colLength = res[0].length;
        for(int res_i = 0; res_i < res_rowLength; res_i++) {
            for(int res_j = 0; res_j < res_colLength; res_j++) {
                bw.write(String.valueOf(res[res_i][res_j]) + " ");
            }
            bw.newLine();
        }

        bw.close();
    }
}
