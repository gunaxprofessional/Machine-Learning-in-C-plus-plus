from sklearn.metrics import multilabel_confusion_matrix, classification_report
import numpy as np

y_true = np.array([
    [0, 0], [0, 1], [1, 1], [0, 1], [0, 1], [1, 1]
])

y_pred = np.array([
    [1, 1], [0, 1], [0, 1], [1, 0], [0, 1], [1, 1]
])

cm = multilabel_confusion_matrix(y_true, y_pred)
print(cm)
print(classification_report(y_true, y_pred))
