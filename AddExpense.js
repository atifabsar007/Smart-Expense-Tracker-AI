import { useState } from "react";
import { addExpense } from "./api";

function AddExpense({ refresh }) {

  const [category, setCategory] = useState("");
  const [amount, setAmount] = useState("");

  const submit = async () => {
    await addExpense({
      category,
      amount: parseFloat(amount)
    });

    setCategory("");
    setAmount("");

    refresh();
  };

  return (
    <div>
      <h3>Add Expense</h3>

      <input
        placeholder="Category"
        value={category}
        onChange={(e) => setCategory(e.target.value)}
      />

      <input
        placeholder="Amount"
        value={amount}
        onChange={(e) => setAmount(e.target.value)}
      />

      <button onClick={submit}>Add</button>
    </div>
  );
}

export default AddExpense;
