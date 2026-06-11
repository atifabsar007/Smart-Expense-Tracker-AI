import axios from "axios";

const API = "http://127.0.0.1:5000";

export const getExpenses = () => axios.get(`${API}/expenses`);
export const addExpense = (data) => axios.post(`${API}/expenses`, data);
export const getAnalytics = () => axios.get(`${API}/analytics`);
