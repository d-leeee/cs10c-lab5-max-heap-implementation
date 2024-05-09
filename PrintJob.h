class PrintJob {
  private:
    int priority;
    int jobNumber;
    int numPages;

  public:
    PrintJob(int setP, int setJ, int numP){
      priority = setP;
      jobNumber = setJ;
      numPages = numP;
    }
    int getPriority() const;
    int getJobNumber() const;
    int getPages() const;
    void getJobDescription() const; //prints the job priority, number, and pages
};