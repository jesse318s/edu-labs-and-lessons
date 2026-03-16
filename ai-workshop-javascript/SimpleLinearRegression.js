// Simple linear regression for predicting house prices
export class SimpleLinearRegression {
  constructor() {
    this.slope = 0;
    this.intercept = 0;
    this.isTrained = false;
  }

  // Train the model with x (features) and y (target values)
  train(x, y) {
    if (x.length !== y.length) {
      throw new Error("Feature and target arrays must have the same length");
    }

    const n = x.length;
    const xMean = x.reduce((a, b) => a + b) / n;
    const yMean = y.reduce((a, b) => a + b) / n;

    let numerator = 0;
    let denominator = 0;

    // Calculate slope using least squares method
    for (let i = 0; i < n; i++) {
      numerator += (x[i] - xMean) * (y[i] - yMean);
      denominator += Math.pow(x[i] - xMean, 2);
    }

    this.slope = numerator / denominator;
    this.intercept = yMean - this.slope * xMean;
    this.isTrained = true;
  }

  // Predict y value for given x
  predict(x) {
    if (!this.isTrained) {
      throw new Error("Model must be trained before making predictions");
    }

    return this.slope * x + this.intercept;
  }

  // Get model parameters
  getParameters() {
    return {
      slope: this.slope,
      intercept: this.intercept,
      equation: `y = ${this.slope.toFixed(2)}x + ${this.intercept.toFixed(2)}`,
    };
  }
}

// Create pre-trained house price predictor
export function createHousePricePredictor() {
  // Sample data: house sizes (sq ft) and prices ($1000s)
  const houseSizes = [
    1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000,
  ];
  const housePrices = [150, 180, 210, 240, 270, 300, 330, 360, 390, 420, 450];

  // Create and train the regression model
  const regression = new SimpleLinearRegression();
  regression.train(houseSizes, housePrices);

  return regression;
}
