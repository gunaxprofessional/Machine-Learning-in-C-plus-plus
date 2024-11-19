from sklearn.metrics import log_loss

# True labels (binary)
y_true = [0, 1, 1, 0, 1]

# Predicted probabilities for the positive class
y_pred = [0.1, 0.9, 0.8, 0.3, 0.7]

# Calculate log loss
loss = log_loss(y_true, y_pred)
print("Log Loss (Binary):", loss)
