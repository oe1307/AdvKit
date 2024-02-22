import sys

from robustbench import load_model

model = sys.argv[1]

model = load_model(model, root, dataset, norm=norm)
