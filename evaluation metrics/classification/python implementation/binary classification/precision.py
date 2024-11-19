from sklearn.metrics import precision_score

# True labels
y_true = [1, 0, 0, 0, 0, 1, 1, 0, 0, 0]

# Predicted labels
y_pred = [0, 1, 1, 0, 0, 0, 1, 0, 0, 0]

# Precision
precision = precision_score(y_true, y_pred)
print("Precision:", precision)
