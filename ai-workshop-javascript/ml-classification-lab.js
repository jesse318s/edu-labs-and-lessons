// K-Nearest Neighbors classifier for iris flower prediction
export class KNearestNeighbors {
  constructor() {
    this.dataset = [];
  }

  // Train the model with feature-label pairs
  train(features, labels) {
    this.dataset = features.map((feature, index) => ({
      features: feature,
      label: labels[index],
    }));
  }

  // Calculate Euclidean distance between two feature vectors
  calculateDistance(a, b) {
    return Math.sqrt(
      a.reduce((sum, val, i) => sum + Math.pow(val - b[i], 2), 0),
    );
  }

  // Predict the label for given features using k=1 (nearest neighbor)
  predict(features) {
    if (this.dataset.length === 0) {
      throw new Error("Model must be trained before making predictions");
    }

    let minDist = Infinity;
    let prediction = null;

    this.dataset.forEach((sample) => {
      const dist = this.calculateDistance(sample.features, features);
      if (dist < minDist) {
        minDist = dist;
        prediction = sample.label;
      }
    });

    return prediction;
  }
}

// Simple decision tree for iris classification
export class DecisionTree {
  constructor() {
    this.rules = {
      feature: 2, // petal length index
      thresholds: [2.5, 4.8],
      labels: ["setosa", "versicolor", "virginica"],
    };
  }

  // Predict using simple threshold rules based on petal length
  predict(features) {
    const featureValue = features[this.rules.feature];

    if (featureValue <= this.rules.thresholds[0]) {
      return this.rules.labels[0]; // setosa
    } else if (featureValue <= this.rules.thresholds[1]) {
      return this.rules.labels[1]; // versicolor
    } else {
      return this.rules.labels[2]; // virginica
    }
  }
}

// Create pre-trained classifiers with sample iris data
export function createPretrainedIrisClassifiers() {
  // Sample iris dataset - features: [sepal_length, sepal_width, petal_length, petal_width]
  const irisFeatures = [
    // Setosa samples
    [5.1, 3.5, 1.4, 0.2],
    [4.9, 3.0, 1.4, 0.2],
    [4.7, 3.2, 1.3, 0.2],
    [4.6, 3.1, 1.5, 0.2],
    [5.0, 3.6, 1.4, 0.2],

    // Versicolor samples
    [7.0, 3.2, 4.7, 1.4],
    [6.4, 3.2, 4.5, 1.5],
    [6.9, 3.1, 4.9, 1.5],
    [5.5, 2.3, 4.0, 1.3],
    [6.5, 2.8, 4.6, 1.5],

    // Virginica samples
    [6.3, 3.3, 6.0, 2.5],
    [5.8, 2.7, 5.1, 1.9],
    [7.1, 3.0, 5.9, 2.1],
    [6.3, 2.9, 5.6, 1.8],
    [6.5, 3.0, 5.8, 2.2],
  ];

  const irisLabels = [
    // Labels for setosa
    "setosa",
    "setosa",
    "setosa",
    "setosa",
    "setosa",
    // Labels for versicolor
    "versicolor",
    "versicolor",
    "versicolor",
    "versicolor",
    "versicolor",
    // Labels for virginica
    "virginica",
    "virginica",
    "virginica",
    "virginica",
    "virginica",
  ];

  // Create and train KNN classifier
  const knn = new KNearestNeighbors();
  knn.train(irisFeatures, irisLabels);

  // Create decision tree (pre-configured with rules)
  const decisionTree = new DecisionTree();

  return { knn, decisionTree };
}
