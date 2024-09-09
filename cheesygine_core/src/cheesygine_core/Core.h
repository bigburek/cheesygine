class Core {
public:
    Core(const Core&) = delete;
    Core& operator=(const Core&) = delete;
    static Core& getInstance() {
        static Core instance;
        return instance;
    }
private:
    Core() {};
public:
    int CheesyInit(void);

};