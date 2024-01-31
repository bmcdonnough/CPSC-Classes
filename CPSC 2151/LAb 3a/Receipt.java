/**
 * This class, written for CPSC2151, stores information 
 * for a receipt. Specifically, the class stores the taxable
 * and nontaxable subtotals, allows users to add items to the
 * receipt, and returns the net receipt total according to 
 * a user-specified tax rate.
 *
 * @authors Ben McDonnough, Evan Cox, Grant Benson
 * @version 1.0
 *
 * @invariant taxRate >= 0 AND taxableTotal >= 0 AND nontaxableTotal >= 0
 */
 
public class Receipt {

    private final static double taxRateConst;
    private double taxableTotal;
    private double nontaxableTotal;
    
    /** 
     * Constructs a receipt object with a certain taxRate that will be applied to items.
     *
     * @param taxRate the rate of tax that will be added to the items
     * @pre taxRate >= 0
     * @post getTaxRate = taxRate
     */
    public Receipt(double taxRate) {}

    /** 
     * Adds items to the receipt having a cost and quantity.
     * Can be taxable or non-taxable.
     *
     * @param cost the cost of the item
     * @param quantity how many of the item you have
     * @param isTaxable whether or not the item can be taxed
     *
     * @pre cost >= 0 AND quantity >= 0
     *
     * @post getTaxableSubtotal += (cost * quantity) if and only if isTaxable
     *       getNonTaxableSubtotal += (cost * quantity) if and only if !isTaxable
     */
    public void addToReceipt(double cost, int quantity, boolean isTaxable) {}

    /** 
     * Returns the sum of all non-taxable items on the receipt.
     *
     * @return nontaxableTotal
     *
     * @pre none
     *
     * @post nontaxableTotal >= 0.0;
     */
    public double getNonTaxableSubtotal() {}

    /**  
     * Returns the sum of all taxable items on the receipt.
     *
     * @return taxableTotal
     *
     * @pre none
     *
     * @post taxableTotal >= 0.0;
     */
    public double getTaxableSubtotal() {}

    /** 
     * Returns the taxRate for the receipt object.
     *
     * @return the taxRate for the receipt object.
     * 
     * @pre none
     *
     * @post taxRate >= 0
     */
    public double getTaxRate() {}

    /** 
     * Returns the total price for the receipt.
     *
     * @return taxableTotal + nontaxableTotal
     *
     * @pre none
     *
     * @post taxableTotal + nontaxableTotal >= 0
     */
    public double computeTotal() {}
}
