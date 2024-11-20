from sklearn.metrics import precision_score, recall_score, f1_score
y_true = [1, 0, 1, 2, 0, 1, 0, 0, 1, 2]
y_pred = [0, 0, 0, 2, 0, 1, 0, 1, 2, 2]
score = precision_score(y_true, y_pred, average='macro')
score1 = recall_score(y_true, y_pred, average='macro')
f1_score = f1_score(y_true, y_pred, average='macro')
print("Precision score: ", score)
print("Recall score: ", score1)
print("F1 Score: ", f1_score)
