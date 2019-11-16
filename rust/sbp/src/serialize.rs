pub trait SbpSerialize {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>);
    fn sbp_size(&self) -> usize;
}

impl SbpSerialize for u8 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        1
    }
}

impl SbpSerialize for u16 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        2
    }
}

impl SbpSerialize for u32 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        4
    }
}

impl SbpSerialize for u64 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        8
    }
}

impl SbpSerialize for i8 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        1
    }
}

impl SbpSerialize for i16 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        2
    }
}

impl SbpSerialize for i32 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes())
    }

    fn sbp_size(&self) -> usize {
        4
    }
}

impl SbpSerialize for i64 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(&self.to_le_bytes());
    }

    fn sbp_size(&self) -> usize {
        8
    }
}

impl SbpSerialize for f32 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        // This really should be self.to_le_bytes().to_vec() once it's a stable feature
        buf.extend(&self.to_bits().to_le_bytes());
    }

    fn sbp_size(&self) -> usize {
        4
    }
}

impl SbpSerialize for f64 {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        // This really should be self.to_le_bytes().to_vec() once it's a stable feature
        buf.extend(&self.to_bits().to_le_bytes());
    }

    fn sbp_size(&self) -> usize {
        8
    }
}

impl SbpSerialize for String {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        buf.extend(self.as_bytes());
    }

    fn sbp_size(&self) -> usize {
        self.len()
    }
}

impl<T: SbpSerialize> SbpSerialize for Vec<T> {
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        for item in self.into_iter() {
            item.append_to_sbp_buffer(buf);
        }
    }

    fn sbp_size(&self) -> usize {
        let mut total = 0;
        for item in self.iter() {
            total += item.sbp_size();
        }
        total
    }
}
