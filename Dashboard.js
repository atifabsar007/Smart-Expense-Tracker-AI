import { useEffect, useState } from "react";
import { getExpenses, getAnalytics } from "./api";
import AddExpense from "./AddExpense";

function Dashboard() {

  const [expenses, setExpenses] = useState([]);
  const [analytics, setAnalytics] = useState({});

  const load = async () => {
    const e = await getExpenses();
    const a = await getAnalytics();

    setExpenses(e.data);
    setAnalytics(a.data);
  };

  useEffect(() => {
    load();
  }, []);

  return (
    <div>

      <AddExpense refresh={load} />

      <h2>📊 Analytics</h2>
      <p>Total: {analytics.total}</p>
      <p>Top Category: {analytics.top_category}</p>
      <p>Total Expenses: {analytics.count}</p>

      <h2>📌 Expenses</h2>

      <ul>
        {expenses.map((e, i) => (
          <li key={i}>
            {e.category} - {e.amount}
          </li>
        ))}
      </ul>

    </div>
  );
}

export default Dashboard;
