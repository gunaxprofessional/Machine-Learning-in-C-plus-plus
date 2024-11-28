from sklearn.metrics import matthews_corrcoef
y_true = [1, 0, 1, 2, 0, 1, 0, 0, 1, 2]
y_pred = [0, 0, 0, 2, 0, 1, 0, 1, 2, 2]
print(matthews_corrcoef(y_true, y_pred))
