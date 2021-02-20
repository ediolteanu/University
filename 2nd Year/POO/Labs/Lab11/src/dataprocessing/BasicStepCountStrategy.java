package dataprocessing;

import storage.DataRepository;
import storage.SensorData;

class BasicStepCountStrategy implements StepCountStrategy {

    @Override
    public int getTotalSteps() {
        int count = 0;
        for (SensorData data : DataRepository.getData()) {
            count += data.getStepsCount();
        }
        return count;
    }

    @Override
    public String getStrategyDescription() {
        return "Basic Step Count Strategy";
    }
}