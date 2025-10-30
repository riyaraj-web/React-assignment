

class Spreadsheet {
    private Map<String, Integer> cells = new HashMap<>();

    public Spreadsheet(int rows) {
    }

    public void setCell(String cell, int value) {
        cells.put(cell, value);
    }

    public void resetCell(String cell) {
        cells.remove(cell);
    }

    public int getValue(String formula) {
        // remove leading '=' if present
        if (formula.startsWith("=")) {
            formula = formula.substring(1);
        }

        // split by '+'
        String[] parts = formula.split("\\+");
        int result = 0;

        for (String part : parts) {
            part = part.trim();

            int value;
            if (Character.isLetter(part.charAt(0))) {
                // It's a cell reference
                value = cells.getOrDefault(part, 0);
            } else {
                // It's a number
                value = Integer.parseInt(part);
            }
            result += value;
        }

        return result;
    }
}
