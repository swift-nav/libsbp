use std::marker::PhantomData;

pub trait HandleSbpMessage {
    fn handle_message(&mut self, _msg: &crate::messages::SBP);
}

pub struct Handler<T: crate::messages::SBPMessage, U: FnMut(&T)> {
    func: U,
    phantom_data: PhantomData<T>,
}

impl<T, U> Handler<T, U>
where
    T: crate::messages::SBPMessage,
    U: FnMut(&T),
{
    pub fn new(func: U) -> Self {
        Self {
            func,
            phantom_data: PhantomData,
        }
    }

    pub fn handle(&mut self, msg: &T) {
        (self.func)(msg)
    }
}
