from sklearn.metrics import accuracy_score

# True labels (multiclass)
y_true = [0, 1, 2, 2, 1, 0, 1, 2, 0, 1]

# Predicted labels
y_pred = [0, 1, 2, 0, 1, 0, 2, 2, 0, 1]

# Calculate accuracy
accuracy = accuracy_score(y_true, y_pred)
print("Accuracy:", accuracy)
