import java.util.Random;

public class ShuffleCards {
    public static void shuffle(Object[] deck) {
        Random random = new Random();
        for (int i = 0; i < deck.length - 1; ++i) {
            int r = random.nextInt(deck.length - i) + i;
            Object tmp = deck[i];
            deck[i] = deck[r];
            deck[r] = tmp;
        }
    }

    public static void main(String[] args) {
        Integer[] deck = new Integer[Integer.parseInt(args[0])];
        for (Integer i = 0; i < deck.length; ++i)
            deck[i] = i + 1;
        shuffle(deck);
        for (Integer card : deck) System.out.print(card + " ");
        System.out.println();
    }
}
