type EventCallback<T = any> = (data: T) => void;

class TypedEventEmitter<Events extends Record<string, any>> {
    private events: Partial<{ [K in keyof Events]: EventCallback<Events[K]>[] }> = {};

    on<K extends keyof Events>(eventName: K, callback: EventCallback<Events[K]>) {
        if (!this.events[eventName]) this.events[eventName] = [];
        this.events[eventName]!.push(callback);
    }

    emit<K extends keyof Events>(eventName: K, data: Events[K]) {
        const listeners = this.events[eventName];
        if (!listeners) return;
        listeners.forEach(cb => cb(data));
    }

    off<K extends keyof Events>(eventName: K, callback: EventCallback<Events[K]>) {
        const listeners = this.events[eventName];
        if (!listeners) return;
        this.events[eventName] = listeners.filter(cb => cb !== callback);
    }
}

// Usage
interface Events {
    login: { userId: string };
    logout: void;
}

const emitter = new TypedEventEmitter<Events>();
emitter.on("login", data => console.log(data.userId));
emitter.emit("login", { userId: "abc123" });
