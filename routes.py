from flask import Blueprint, request, jsonify
import json

routes = Blueprint("routes", __name__)

FILE = "backend/data.json"


def load_data():
    try:
        with open(FILE, "r") as f:
            return json.load(f)
    except:
        return []


def save_data(data):
    with open(FILE, "w") as f:
        json.dump(data, f, indent=4)


@routes.route("/expenses", methods=["GET"])
def get_expenses():
    return jsonify(load_data())


@routes.route("/expenses", methods=["POST"])
def add_expense():
    data = load_data()
    new_expense = request.json
    data.append(new_expense)
    save_data(data)
    return jsonify({"message": "added"})


@routes.route("/analytics", methods=["GET"])
def analytics():

    data = load_data()

    total = sum(x["amount"] for x in data)

    categories = {}

    for x in data:
        cat = x["category"]
        categories[cat] = categories.get(cat, 0) + x["amount"]

    top = max(categories, key=categories.get) if categories else None

    return jsonify({
        "total": total,
        "top_category": top,
        "count": len(data)
    })
